
#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <string.h>

#include "astree.h"
#include "astree.rep.h"
#include "lyutils.h"
#include "attributes.h"
#include "sym_tab.h"

static char *astree_tag = "struct astree_rep";

bool is_astree (void *object) {
   astree tree = (astree) object;
   return tree != NULL && tree->tag == astree_tag;
}

astree new_astree (int symbol, int filenr, int linenr, int offset,
                   char *lexinfo ) {
   size_t size = sizeof (struct astree_rep);
   astree tree = malloc (size);
   assert (tree != NULL);
   tree->tag = astree_tag;
   tree->symbol = symbol;
   tree->filenr = filenr;
   tree->linenr = linenr;
   tree->offset = offset;
   tree->lexinfo = intern_stringtable(str_table, lexinfo);
   assert (tree->lexinfo != NULL);
   tree->first = NULL;
   tree->last = NULL;
   tree->next = NULL;
   tree->attribute = 0;
   tree->blockno = 0;
   tree->blockstruct = NULL;
   //tree->struct_tb = NULL;
   DEBUGF ('f', "malloc (%d) = %p-> %d:%d.%d: %s: %p->\"%s\"\n",
           size, tree, tree->filenr, tree->linenr, tree->offset,
           get_yytname (tree->symbol), 
           peek_stringtable(tree->lexinfo),
           peek_stringtable(tree->lexinfo));
   return tree;
}

astree adopt (astree root, ...) {
   va_list children;
   assert (is_astree (root));
   va_start (children, root);
   for(;;) {
      astree child = va_arg (children, astree);
      if (child == NULL) break;
      assert (is_astree (child));
      if (root->last == NULL) root->first = child;
                         else root->last->next = child;
      root->last = child;
      DEBUGF ('a', "%p (%s) adopting %p (%s)\n",
              root, peek_stringtable(root->lexinfo),
              child, peek_stringtable(child->lexinfo));
   }
   va_end (children);
   return root;
}

astree adopt2 (astree root, astree left, astree right) {
   return adopt (root, left, right, NULL);
}

astree adopt1 (astree root, astree child) {
   return adopt (root, child, NULL);
}

astree adopt1sym (astree root, astree child, int symbol) {
   root = adopt1 (root, child);
   root->symbol = symbol;
   return root;
}

astree changesym (astree root, int symbol) {
    root->symbol = symbol;
    return root;
}

//Specification formatted recursion fprintf
static void dump_node_format (FILE *outfile, astree node) {
   assert (is_astree (node));
   const char *tname = get_yytname (node->symbol);
   if (strstr (tname, "TOK_") == tname) tname += 4;
   fprintf (outfile, "%s \"%s\" %d.%d.%d ",
                tname, peek_stringtable(node->lexinfo),
                node->filenr, node->linenr, node->offset);
   if (node->blockstruct != NULL)
      fprintf (outfile, "{%s} ", node->blockstruct);
   else
      fprintf (outfile, "{%d} ", node->blockno);
   print_attributes(node->attribute, outfile);
}
//Specification formatted recursion fprintf
static void dump_astree_rec_format (FILE *outfile, 
                                    astree root, int depth) {
   astree child = NULL;
   if (root == NULL) return;
   assert (is_astree (root));
   
   for (int i = 0; i < depth; i++)
      fprintf(outfile, "|  "); 
   
   dump_node_format (outfile, root);
   for (child = root->first; child != NULL; child = child->next) {
      dump_astree_rec_format (outfile, child, depth + 1);
   }
}
//Specification formatted recursion fprintf
void dump_astree_format (FILE *outfile, astree root) {
   dump_astree_rec_format (outfile, root, 0);
   fflush (NULL);
}

void yyprint (FILE *outfile, unsigned short toknum, astree yyvaluep) {
   fprintf (outfile, "%d=%s)\n%*s(",
             toknum, get_yytname (toknum), 9, "");
   if (is_astree (yyvaluep)) {
      dump_node_format (outfile, yyvaluep);
   }else{
      fprintf (outfile, "yyvaluep = %p", (void*) yyvaluep);
   }
   fflush (NULL);
}

void freeast (astree root) {
   astree child = NULL;
   if (root == NULL) return;
   assert (is_astree (root));
   for (child = root->first; child != NULL;) {
      astree asttofree = child;
      assert (is_astree (asttofree));
      child = child->next;
      freeast (asttofree);
   }
   DEBUGF ('f', "free [%X]-> %d:%d.%d: %s: %p->\"%s\")\n",
           (uintptr_t) root, root->filenr, root->linenr, root->offset,
            get_yytname (root->symbol), 
            peek_stringtable(root->lexinfo), 
            peek_stringtable(root->lexinfo));
   free (root->lexinfo); //Will be freed by stringtable function
   memset (root, 0, sizeof (struct astree_rep));
   free (root);
}







/********************************************************************/






void global (astree node) {
    if (node == NULL) 
        return;
        
    //create global symbol tables, hashstack structure
    sym_table = new_symtab();
    struct_table = new_symtab();
    blockno_stack = new_blockno_stack();
    //ident_stack = NULL;
        
    node = node->first;
    while (node != NULL) {
        bigswitch_t(node);
        node = node->next;
    }
}

void n_return (astree node) {
    bigswitch_t(node->first);
}

static void n_comparison (astree node) {        //<, <=, >, >=
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !(is_primitive(node->first->attribute, node->last->attribute)))
    {    
        //printf("Exprs for primitive comparison do not match.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_BOOL);
}

static void n_unaryposneg (astree node) {
    bigswitch_t(node->first);
    
    //check if child has int attribute, if not exit
    if ( !(is_int(node->first->attribute))) {
        //printf("Exprs for unary operator invalid.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_INT);
}

static void n_binaryop (astree node) {     //+, -, *, /, %
    //visit children first
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !(is_int(node->first->attribute)) || //false
         !(is_int(node->last->attribute)))
    {
        //printf("Exprs for binaryop do not match.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_INT);
}    

static void n_null (astree node) {
    node->attribute |= bitset(ATTR_INDEX_CONST);
    node->attribute |= bitset(ATTR_INDEX_NULL);
} 

static void n_boolcon (astree node) {
    node->attribute |= bitset(ATTR_INDEX_CONST);
    node->attribute |= bitset(ATTR_INDEX_BOOL);
} 

static void n_intcon (astree node) {
    node->attribute |= bitset(ATTR_INDEX_CONST);
    node->attribute |= bitset(ATTR_INDEX_INT);
}

static void n_charcon (astree node) {
    node->attribute |= bitset(ATTR_INDEX_CONST);
    node->attribute |= bitset(ATTR_INDEX_CHAR);
}

static void n_stringcon (astree node) {
    node->attribute |= bitset(ATTR_INDEX_CONST);
    node->attribute |= bitset(ATTR_INDEX_STRING);
}

static void n_int (astree node) {
    astree node_child = node->first;
    while (node_child != NULL) {
        node->last->attribute |= bitset(ATTR_INDEX_INT);
        node->last->attribute |= bitset(ATTR_INDEX_VARIABLE);
        node->last->attribute |= bitset(ATTR_INDEX_LVALUE);
        
        if (node->blockstruct != NULL)
            node->last->blockstruct = node->blockstruct;
        
        bigswitch_t(node_child);
        node_child = node_child->next;
    }
    
    node->attribute |= bitset(ATTR_INDEX_INT);          //set self attribute
}

static void n_char (astree node) {
    astree node_child = node->first;
    while (node_child != NULL) {
        node->last->attribute |= bitset(ATTR_INDEX_CHAR);
        node->last->attribute |= bitset(ATTR_INDEX_VARIABLE);
        node->last->attribute |= bitset(ATTR_INDEX_LVALUE);
        
        if (node->blockstruct != NULL)
            node->last->blockstruct = node->blockstruct;
        
        bigswitch_t(node_child);
        node_child = node_child->next;
    }
    
    node->attribute |= bitset(ATTR_INDEX_CHAR);
}

static void n_bool (astree node) {
    astree node_child = node->first;
    while (node_child != NULL) {
        node->last->attribute |= bitset(ATTR_INDEX_BOOL);
        node->last->attribute |= bitset(ATTR_INDEX_VARIABLE);
        node->last->attribute |= bitset(ATTR_INDEX_LVALUE);
        
        if (node->blockstruct != NULL)
            node->last->blockstruct = node->blockstruct;
        
        bigswitch_t(node_child);
        node_child = node_child->next;
    }
    
    node->attribute |= bitset(ATTR_INDEX_BOOL);
}

static void n_string (astree node) {
    astree node_child = node->first;
    while (node_child != NULL) {
        node->last->attribute |= bitset(ATTR_INDEX_STRING);
        node->last->attribute |= bitset(ATTR_INDEX_VARIABLE);
        node->last->attribute |= bitset(ATTR_INDEX_LVALUE);
        
        if (node->blockstruct != NULL)
            node->last->blockstruct = node->blockstruct;
        
        bigswitch_t(node_child);
        node_child = node_child->next;;
    }

    node->attribute |= bitset(ATTR_INDEX_STRING);
}

void n_anytype_compare (astree node) {
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !(is_anytype(node->first->attribute, node->last->attribute)))
    {
        //print_attributes(node->first->attribute, stdout);
        //print_attributes(node->last->attribute, stdout);
        //printf("Exprs for anytype comparison do not match.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_BOOL);
}

void n_notop (astree node) {    //! operator
    bigswitch_t(node->first);
    
    if ( !(is_bool(node->first->attribute))) {
        //printf("Exprs for ! is not bool.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_BOOL);
}    

void n_ord (astree node) {
    bigswitch_t(node->first);
    
    if ( !(is_char(node->first->attribute))) {
        //printf("Exprs for ord is not char.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_INT);
}

void n_chr (astree node) {
    bigswitch_t(node->first);
    
    if ( !(is_int(node->first->attribute))) {
        //printf("Exprs for chr is not int.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= bitset(ATTR_INDEX_CHAR);
}

void n_newarray (astree node) { //only for array types bool char int
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !(is_int(node->last->attribute)) ||    //length is [int] and not ["str"]
        //is actual array type
        !(is_primitive(node->first->attribute, node->first->attribute)))
    {
        //printf("Basetype array operands not correct.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_ARRAY);
    node->attribute |= bitset(ATTR_INDEX_VREG);
    node->attribute |= node->first->attribute;
}

void n_newstring (astree node) { //only for array string
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !(is_int(node->last->attribute)) ||     //length is [int] and not ["str"]
         !(is_string(node->first->attribute)))   //is actual array type
    {
        //printf("String array operands not correct.\n");
        return;
    }
    
    node->attribute |= bitset(ATTR_INDEX_STRING);
    node->attribute |= bitset(ATTR_INDEX_VREG);
}

void n_vardecl (astree node) {  //int n = 5; no attr set, enter into symtab
    bigswitch_t(node->first);
    bigswitch_t(node->last);

    if ( !is_anytype(node->first->attribute, node->last->attribute)) {
        //printf("Variable declaration not compatible types.\n");
        return;
    }
}

//fix later using symtab
static void n_asg (astree node) {          //=
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    //need to fix type checking, do it later
    if ( !is_lvalue(node->first->attribute)  ||    //lvalue
         !is_anytype(node->last->attribute, node->first->attribute)) //2 types are same
    {
        //printf("Variable assigment not compatible types.\n");
        return;
    }

    node->attribute |= bitset(ATTR_INDEX_VREG);   
    //node->attribute |= node->first->attribute;     //not sure if needed
}

void n_declid (astree node) {
    if (check_table(node) == true) { //duplication node already in symtable
        //printf("*Duplication error %s already in symtable.*\n", 
                                    //peek_stringtable(node->lexinfo));
        return;
    }
    
    if (is_function(node->attribute))
        return;
    
    //node->attribute |= bitset(ATTR_INDEX_VARIABLE);
    //node->attribute |= bitset(ATTR_INDEX_LVALUE);

    //enter into symbol table
    //printf("*Entered %s into symbol table and ident stack*\n", 
                                    //peek_stringtable(node->lexinfo));
                                    
    symnode_ref new_node = intern_symtable(sym_table, node);
    push_ident_stack(new_node);
}


//block functions
/******************************************************************/

void n_while (astree node) {
    bigswitch_t(node->first);
    bigswitch_t(node->last);
    
    if ( !is_bool(node->first->attribute)) {
        //printf("Exprs for while condition is not bool.\n");
        return;
    }
    
    //entered block
    
    //set no attribute
}

void n_if (astree node) {
    enter_block(blockno_stack);
    bigswitch_t(node->first);
    bigswitch_t(node->first->next);
    exit_block();
    
    if ( !is_bool(node->first->attribute)) {
        //printf("Exprs for while condition is not bool.\n");
        return;
    }
    //set no attribute
}

void n_block_child (astree node) {
    if (node == NULL)
        return;
    bigswitch_t(node);
    n_block_child(node->next);
}

void n_block (astree node) {            //'{'
    if (!is_function(node->attribute))  //dont want to double increment for functions
        enter_block(blockno_stack);     // we're in a new block
    
    n_block_child(node->first);
    // pop all locals, new block
    exit_block();
}    


void change_blockno (astree node) {
    node->blockno = get_blockno (blockno_stack);
}


/******************************************************************/


void n_ident (astree node) {
    //is node in sym table
    if (check_table(node) == false) { //node not found in symtable
        ;//printf("*Identifier %s not found in symtable.*\n", peek_stringtable(node->lexinfo));
    }
    else {
        ;//printf("*Identifier %s found in symtable.*\n", peek_stringtable(node->lexinfo));
    }
}

void n_struct (astree node) {
    node->attribute |= bitset(ATTR_INDEX_STRUCT);
    node->first->blockstruct = peek_stringtable(node->first->lexinfo);
    bigswitch_t(node->first);
}

void n_typeid (astree node) {
    //set attribute for self
    node->attribute |= bitset(ATTR_INDEX_STRUCT);
    node->attribute |= bitset(ATTR_INDEX_TYPEID);

    //loop through all children and set attr
    astree node_child = node->first;
    while (node_child != NULL) {
        node_child->blockstruct = node->blockstruct;
        //Need to check if parent is of type struct i.e. struct field is a struct
        if (node->first->symbol == TOK_FIELD) {
            node->first->attribute |= bitset(ATTR_INDEX_STRUCT);
            node->first->attribute |= bitset(ATTR_INDEX_TYPEID);
        }
    
        bigswitch_t(node_child);
        node_child = node_child->next;
    }

    symnode_ref structnode_ref = intern_symtable(struct_table, node);
    node->struct_node = structnode_ref;
    //printf("%s\n", peek_symtable(structnode_ref)); //prints twice because called twice
}

void n_field (astree node) {
    node->attribute |= bitset(ATTR_INDEX_LVALUE);
    node->attribute |= bitset(ATTR_INDEX_VARIABLE);
    node->attribute |= bitset(ATTR_INDEX_FIELD);
    
    if (node->next != NULL)
        node->next->attribute = node->attribute;
}

void n_function (astree node) {
    //set function name to have function attribute
    node->first->first->attribute |= bitset(ATTR_INDEX_FUNCTION);

    bigswitch_t(node->first);                    //first child 'type'

    enter_block(blockno_stack);
    bigswitch_t(node->first->next);              //second child paramlist
    
    //check inside node. if function dont increment block
    node->last->attribute |= bitset(ATTR_INDEX_FUNCTION);
    bigswitch_t(node->last);                     //third child 'block'
    
    node->attribute |= bitset(ATTR_INDEX_FUNCTION);
    node->attribute |= node->first->attribute;
    
    //printf("Entering function %s into symtable\n", peek_stringtable(node->lexinfo));
    intern_symtable(sym_table, node);
}

void n_paramlist (astree node) {        //insert into paramlist in node
    astree child = node->first;
    
    while (child != NULL) {
        child->first->attribute |= bitset(ATTR_INDEX_PARAM);
        bigswitch_t(child);
        child = child->next;
    }

}

void n_ifelse (astree node) {
    enter_block(blockno_stack);
    bigswitch_t(node->first);
    bigswitch_t(node->first->next);           //if statement
    enter_block(blockno_stack);
    bigswitch_t(node->first->next->next);     //else statement
    exit_block();
    exit_block();

    if ( !is_bool(node->first->attribute)) {
        //printf("Exprs for while condition is not bool.\n");
        return;
    }
}

//need to manual check IDENT "function name"
void n_call (astree node) {

    //bigswitch_t(node->first);             //type declaration of function
    node->first->attribute |= bitset(ATTR_INDEX_FUNCTION);

    astree child = node->first->next;   //function parameter list
    while (child != NULL) {
        bigswitch_t(child);
        child = child->next;
    }
    
    //look up call in symbol table
    /*
    if (check_table(node->first) == false) //node not found in symtable
        printf("*Function %s not found in symtable.*\n", 
                                        peek_stringtable(node->lexinfo));
    */
}

void n_array (astree node) {
    node->attribute |= bitset(ATTR_INDEX_ARRAY);
}

void bigswitch_t (astree node) {
    //printf("at node %s blockno %d\n", get_yytname (node->symbol), 
                                      //get_blockno (blockno_stack));
    change_blockno(node);
    switch (node->symbol)
    {
        case TOK_ARRAY:
            n_array(node);
            break;
    
        case TOK_CALL:
            n_call(node);
            break;
        case TOK_IFELSE:
            n_ifelse(node);
            break;
        case TOK_PARAMLIST:
            n_paramlist(node);
            break;
        case TOK_FUNC:
            n_function(node);
            break;
        case TOK_FIELD:
            n_field(node);
            break;
        case TOK_TYPEID:
            n_typeid(node);
            break;
        case TOK_STRUCT:
            n_struct(node);
            break;
        case TOK_IDENT:
            n_ident(node);
            break;
        case TOK_BLOCK:
            n_block(node);
            break;
        case TOK_WHILE:
            n_while(node);
            break;
        case TOK_IF:
            n_if(node);
            break;
        case '=':               //fix any type check
            n_asg(node);
            break;
        case TOK_VARDECL:       //int n = 5;
            n_vardecl(node);
            break;
        case TOK_DECLID:
            n_declid(node);
            break;
    
        //case struct typeid
        case TOK_NEWSTRING:
            n_newstring(node);
            break;
        case TOK_NEWARRAY:
            n_newarray(node);
            break;
        case '!':
            n_notop(node);
            break;
        case TOK_ORD:
            n_ord(node);
            break;
        case TOK_CHR:
            n_chr(node);
            break; 
        case TOK_RETURN:
            n_return(node);
            break;
        case TOK_EQ:
            n_anytype_compare(node);        //fix
            break;
        case TOK_NE:
            n_anytype_compare(node);        //fix
            break;
        case TOK_LT:
            n_comparison(node);
            break;
        case TOK_LE:
            n_comparison(node);
            break;
        case TOK_GE:
            n_comparison(node);
            break;
        case TOK_GT:
            n_comparison(node);
            break;
        case '+':
            n_binaryop(node);
            break;
        case '-':
            n_binaryop(node);
            break;
        case '*':
            n_binaryop(node);
            break;
        case '/':
            n_binaryop(node);
            break;
        case '%':
            n_binaryop(node);
            break;
        case TOK_POS:   //positive -6
            n_unaryposneg(node);
            break;
        case TOK_NEG:   //negative +6
            n_unaryposneg(node);
            break;
        case TOK_INTCON:
            n_intcon(node);
            break;
        case TOK_CHARCON:
            n_charcon(node);
            break;
        case TOK_STRINGCON:
            n_stringcon(node);
            break;
        case TOK_INT:
            n_int(node);
            break;
        case TOK_CHAR:
            n_char(node);
            break;
        case TOK_BOOL:
            n_bool(node);
            break;
        case TOK_STRING:
            n_string(node);
            break;
        case TOK_FALSE:
            n_boolcon(node);
            break;
        case TOK_TRUE:
            n_boolcon(node);
            break;
        case TOK_NULL:
            n_null(node);
            break;
        default:
            printf("astree error did not switch!\n");
            break;
    }
}

