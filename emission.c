#include <assert.h>
#include <inttypes.h>
#include <stdarg.h>
#include <string.h>

#include "emission.h"
#include "astree.h"
#include "astree.rep.h"
#include "lyutils.h"
#include "attributes.h"
#include "sym_tab.h"

//REMEMBER TO USE BIGSWITCH_E OR E_TYPE

int vreg_counter = 1;

void prolog_generation(FILE* IN) {
    fprintf(IN, "#define __OCLIB_C__\n");
    fprintf(IN, "include \"oclib.oh\"\n\n");
}

void print_indents(FILE *IN) {  //print 8 spaces
    //if (node->blockno != 0)
    fprintf(IN, "%8s", "");
}


void e_struct (astree node) {
    //2.visit all struct's children
    bigswitch_e(node->first);
    fprintf(writeto_oil, "};");
}

void e_typeid (astree node) {
    //1.print out struct type
    if (!is_field(node->first->attribute))
        fprintf(writeto_oil, "struct s_%s {\n", peek_symtable(node->struct_node));
    else {
        fprintf(writeto_oil, "struct s_%s *", 
                     peek_symtable(node->struct_node));
    }
    
    //1.variable struct decl, only 1 child
    //2.struct field decl, multiple children
    astree node_child = node->first;
    while (node_child != NULL) {
        if (!is_field(node_child->attribute))
            print_indents(writeto_oil);
        bigswitch_e(node_child);
        node_child = node_child->next;
    }
}

void e_string (astree node) {
    fprintf(writeto_oil, "ubyte *");
    
    astree node_child = node->first;
    while (node_child != NULL) {
        bigswitch_e(node_child);
        node_child = node_child->next;
    }
}

void e_array (void) {
    fprintf(writeto_oil, "*");
}

void e_ident (astree node) {
    fprintf(writeto_oil, "_%s", peek_stringtable(node->lexinfo));
}

void e_field (astree node) {
    fprintf(writeto_oil, "f_%s_%s;\n", 
                node->blockstruct, peek_stringtable(node->lexinfo));
}

void e_int (astree node) {
    fprintf(writeto_oil, "int ");

    astree node_child = node->first;
    while (node_child != NULL) {
        bigswitch_e(node_child);
        node_child = node_child->next;
    }
}

void e_char_bool (astree node) {
    fprintf(writeto_oil, "ubyte ");

    astree node_child = node->first;
    while (node_child != NULL) {
        bigswitch_e(node_child);
        node_child = node_child->next;
    }
}

void e_function (astree node) {
    bigswitch_e(node->first);
    bigswitch_e(node->first->next);
    bigswitch_e(node->last);
    
    
}

void e_declid (astree node) {
    if (is_function(node->attribute))
        fprintf(writeto_oil, "__%s ", peek_stringtable(node->lexinfo));
    else
        fprintf(writeto_oil, "_%d_%s", 
                        node->blockno, peek_stringtable(node->lexinfo));
    
}

void e_paramlist (astree node) {
    fprintf(writeto_oil, "(\n");

    astree node_child = node->first;
    while (node_child != NULL) {
        print_indents(writeto_oil);
        bigswitch_e(node_child);
        fprintf(writeto_oil, ";\n");
        node_child = node_child->next;
    }
       
}

void e_block (astree node) {
    fprintf(writeto_oil, "{\n");
    
    astree node_child = node->first;
    while (node_child != NULL) {
        print_indents(writeto_oil);
        bigswitch_e(node_child);
        fprintf(writeto_oil, ";\n");
        node_child = node_child->next;
    }
}

void e_return (astree node) {
    //print vreg?
    bigswitch_e(node->first);
}

char *vreg_type (astree node) {
    switch (node->symbol)
    {
        case TOK_CHAR:
            return "char b";
            break;
        case TOK_BOOL:
            return "bool b";
            break;
        case TOK_STRING:
            return "string s";
            break;
        case TOK_INT:
            return "int i";
            break;
        default:
            printf("the fuck happened here!\n");
            return "";
            break;
    }
}


void e_binaryop (astree node) {
    //sprintf(node->vreg, "%s%d = ", vreg_type(node), vreg_counter++);
    
    bigswitch_e (node->last);
    fprintf(writeto_oil, " %s ", peek_stringtable(node->lexinfo));
    bigswitch_e (node->first);
    //fprintf(writeto_oil, ";\n");
}


void bigswitch_e (astree node) {
    printf("at node %s blockno %d\n", get_yytname (node->symbol), 
                                        get_blockno (blockno_stack));
    switch (node->symbol)
    {
        case TOK_RETURN:
            e_return(node);
            break;
        
        case TOK_EQ:
            e_binaryop(node);        //fix
            break;
        case TOK_NE:
            e_binaryop(node);        //fix
            break;
        case TOK_LT:
            e_binaryop(node);
            break;
        case TOK_LE:
            e_binaryop(node);
            break;
        case TOK_GE:
            e_binaryop(node);
            break;
        case TOK_GT:
            e_binaryop(node);
            break;
        case '+':
            e_binaryop(node);
            break;
        case '-':
            e_binaryop(node);
            break;
        case '*':
            e_binaryop(node);
            break;
        case '/':
            e_binaryop(node);
            break;
        case '%':
            e_binaryop(node);
            break;
    
        case TOK_BLOCK:
            e_block(node);
            break;
    
        case TOK_PARAMLIST:
            e_paramlist(node);
            break;
    
        case TOK_DECLID:
            e_declid(node);
            break;
        
        case TOK_FUNC:
            e_function(node);
            break;
            
        case TOK_CHAR:
            e_char_bool(node);
            break;
        case TOK_BOOL:
            e_char_bool(node);
            break;
        case TOK_INT:
            e_int(node);
            break;
        case TOK_STRING:
            e_string(node);             //includes arrays
            break;
            
        case TOK_FIELD:
            e_field(node);
            break;
        case TOK_ARRAY:
            e_array();
            break;
        case TOK_IDENT:
            e_ident(node);
            break;
          
        case TOK_TYPEID:
            e_typeid(node);
            break;
	    case TOK_STRUCT:
	        e_struct(node);
	        break;
	    default:
            printf("emission error did not switch!\n");
            break;
    }
}

void global_emission (astree node) {
	//generate a prolog
	prolog_generation(writeto_oil);

    //find all structs first, mangle names, indent fields
	astree temp = node->first;
    while (temp != NULL) {
        if (is_struct(temp->attribute))
            bigswitch_e(temp);
        temp = temp->next;
    }
    
    //all string constants are given names
    
    //output all global variables, immediate children of the root
    
    //all functions are output
    temp = node->first;
    while (temp != NULL) {
        if (is_function(temp->attribute))
            bigswitch_e(temp);
        temp = temp->next;
    }
    
    
    //single function with signature ocmain() output

}



