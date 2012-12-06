#include <inttypes.h>
#include <stdlib.h>
#include <assert.h>
#include "sym_tab.h"
#include "attributes.h"
#include "astree.h"
#include "astree.rep.h"

#define TABLE_NEW_SIZE 31

struct blockno_stack {      //stack of block numbers
    int block_count;
    blockno_stack_ref next;
};

struct ident_stack {        //identifier stack
    symnode_ref symnode_entry;
    ident_stack_ref next;
};

struct symnode {            //typedefd as *symnode_ref
    stringnode_ref strnode_entry;
    bitset_t attribute;
    //pointer to struct table node
    symtab_ref field_table;
    int file, line, offset;
    int blockno;
    astree parameter_list;
    ident_stack_ref ident_stack_next;
    symnode_ref next;
};

struct symtab {             //typedefd as *symtab_ref
    size_t table_length;    //size of table including empty entries
    int entries;
    double load;
    symnode_ref *node_ref_array;
};

int symtab_blockno (symnode_ref entry) {
    return entry->blockno;
}



blockno_stack_ref new_blockno_stack (void) {
    blockno_stack_ref new = malloc (sizeof (struct blockno_stack));
    new->block_count = 0;
    new->next = NULL;
    return new;
}

void push_ident_stack (symnode_ref entry) {
    ident_stack_ref new = malloc (sizeof (struct ident_stack));
    new->symnode_entry = entry;
    new->next = NULL;
    
    //printf("1new address: %p, ident_stack address: %p\n",
                //new, ident_stack);
    
    if (ident_stack == NULL)
        ident_stack = new;
    else {
        new->next = ident_stack;
        ident_stack = new;
    }
    
    //printf("2new address: %p, ident_stack address: %p, ident_stack->next address: %p\n",
                //new, ident_stack, ident_stack->next);
    
    
    
    /*printf("!!!!!!!!!!!!!!!!!!inserted %s into stack\n", 
                peek_stringtable(ident_stack->entry->strnode_entry));
    if (ident_stack->next != NULL)
        printf("******************* block stack: %d | %s\n",
                ident_stack->next->symnode_entry->blockno,
                peek_stringtable(ident_stack->next->symnode_entry->strnode_entry));
    */           
    
}

//side effect: modifying global variable blockno_stack and ident_stack
void popblock_ident_stack (void) {
    //printf("!!!!!!!top of blockno_stack is : %d\n", blockno_stack->block_count);

    while (ident_stack->symnode_entry->blockno > blockno_stack->block_count) {
        //remove ident from hashtable
        remove_ident_symtable(ident_stack->symnode_entry);
        ident_stack = ident_stack->next;
        
        if (ident_stack == NULL)
            return;
    }

    //printf("!!!!!!!After popblock top of ident stack is: %d\n", 
                //ident_stack->symnode_entry->blockno);

}

//side effect: modifying global variable sym_table
void remove_ident_symtable(symnode_ref sym_node) {
    //address of stringnode % table length
    hashcode_t hashVal = (uintptr_t) sym_node->strnode_entry % sym_table->table_length;
    symnode_ref curr_node = sym_table->node_ref_array[hashVal];  //go to hash address
    symnode_ref prev_node = curr_node;
    
    //need to change what is pointed at by sym_table->node_ref_array[hashVal]
    //very inelegant scrub code
    if (strcmp(peek_stringtable(curr_node->strnode_entry), 
               peek_stringtable(sym_node->strnode_entry)) == 0)
    {
        sym_table->node_ref_array[hashVal] = NULL;
        return;
    }        

    while (curr_node != NULL) {
        
        stringnode_ref node1 = sym_node->strnode_entry;
        stringnode_ref node2 = curr_node->strnode_entry;
        
        if ( strcmp(peek_stringtable(node1), peek_stringtable(node2)) == 0) {
            //printf("111prev_node is %p and curr_node is %p\n", prev_node, curr_node);
            //printf("##removed %s from ident table##\n", peek_stringtable(node2));
            
            //delete node2 i.e. node_ref from identifier hashtable
            prev_node->next = curr_node->next;
            
            //printf("222prev_node->next is %p and curr_node is %p\n", prev_node->next, curr_node);
            return;
        }
        
        prev_node = curr_node;
        curr_node = curr_node->next;
        
    }
    //printf("333prev_node is %p and curr_node is %p\n", prev_node, sym_table->node_ref_array[hashVal]);
    //printf("444prev_node->next is %p and curr_node is %p\n\n", prev_node->next, curr_node);
}

void enter_block (blockno_stack_ref t) {  //increase block_count += 1
    blockno_stack_ref new = malloc (sizeof (struct blockno_stack));
    new->block_count = t->block_count + 1;
    new->next = t;
    blockno_stack = new;
}

//side effect: modifying global variable blockno_stack and ident_stack
void exit_block (void) {
    if (blockno_stack->block_count != 0)                //pop block count
        blockno_stack = blockno_stack->next;        
    popblock_ident_stack();                             //pop identifier stack
}

int get_blockno (blockno_stack_ref t) {
   return t->block_count;
}

bool check_table (astree node) {
    hashcode_t hashVal = (uintptr_t) node->lexinfo % sym_table->table_length;
    symnode_ref curr_node = sym_table->node_ref_array[hashVal];

    while (curr_node != NULL) {
        stringnode_ref node1 = node->lexinfo;
        stringnode_ref node2 = curr_node->strnode_entry;
        
        if ( strcmp(peek_stringtable(node1), peek_stringtable(node2)) == 0) {
            if (is_function(node->attribute)) {      //seen function check paramlist
                //loop through both parameter lists and compare each
                //printf("seen the function: %s\n", peek_stringtable(node->lexinfo));
                
                astree paramlist_asnode = node->next;
                while (paramlist_asnode != NULL) {
                
                    //printf("astree plist:"); print_attributes(paramlist_asnode->attribute, stdout);
                    //printf("symtable plist:"); print_attributes(curr_node->attribute, stdout);
                
                    //printf("->astree: %s\n", peek_stringtable(paramlist_asnode->lexinfo));
                    //printf("->symtable: %s\n", peek_stringtable(curr_node->strnode_entry));
                
                    if (is_anytype(paramlist_asnode->attribute, curr_node->attribute))
                        //printf("Incorrect function arguments.\n");
                    curr_node = curr_node->next;
                    paramlist_asnode = paramlist_asnode->next;
                }
                return true;
            }
            
            //set to same attributes as node already in table
            node->attribute = curr_node->attribute;
            //changesym at switch gives current blockno to all nodes
            node->blockno = curr_node->blockno;
            return true;
        }
        
        curr_node = curr_node->next;
    }
    
    return false;
}

    
    
    

























symtab_ref new_symtab(void) {
    symtab_ref new_table = malloc(sizeof (struct symtab));
    assert(new_table != NULL);
    
    new_table->table_length = TABLE_NEW_SIZE;
    new_table->entries = 0;
    new_table->load = 0;
    new_table->node_ref_array = malloc(new_table->table_length * 
                                  sizeof (symnode_ref));
    assert(new_table->node_ref_array != NULL);
    memset(new_table->node_ref_array, 0, new_table->table_length * 
            sizeof (symnode_ref));
    
    return new_table;
}

cstring peek_symtable(symnode_ref node_ref) {
    //printf("%s\n", node_ref->string_entry);
    return peek_stringtable(node_ref->strnode_entry);
}

void check_tablesize (symtab_ref table) {
    table->load = (double) (table->entries) / (table->table_length);
    
    if (table->load >= 0.5) 
        realloc_symtable(table);
}

void copy_attributes (symnode_ref ref1, astree ref2) {
    ref1->strnode_entry = ref2->lexinfo;
    ref1->file = ref2->filenr;
    ref1->line = ref2->linenr;
    ref1->offset = ref2->offset;
    ref1->attribute = ref2->attribute;
    ref1->blockno = ref2->blockno;
    ref1->next = NULL;
}

void internfields_symtable (astree as_node, symnode_ref sym_node){
    sym_node->field_table = new_symtab();

    //loop through all the fields
    astree node_child = as_node->first;
    while (node_child != NULL) {
        intern_symtable(sym_node->field_table, node_child);
        node_child = node_child->next;
    }
}

void internplist_symtable(astree as_node, symnode_ref sym_node) {
    //as_node->first->next          is the paramlist node
    //as_node->first->next->first   is the first child
    
    //use next to get to it's children
    
    if (as_node->first != NULL) {
        //printf("what is this %s\n", peek_stringtable(as_node->first->next->first->lexinfo));
        sym_node->parameter_list = as_node->first->next->first;
        //astree temp = malloc (sizeof (astree_rep))
        //sym_node->strnode_entry =
    }
}

//Intern node into symtable. can be struct also
symnode_ref intern_symtable(symtab_ref table, astree node) {
    //address of stringnode % table length
    hashcode_t hashVal = (uintptr_t) node->lexinfo % table->table_length;
    
    //if node is a struct, use typeid as key. why?????????
    /*
    if (is_struct(node->attribute))
        hashVal = (uintptr_t) peek_stringtable(node->lexinfo) % table->table_length;
    */
    
    symnode_ref node_ref = table->node_ref_array[hashVal];  //go to hash address
    
    symnode_ref new_node = malloc(sizeof (struct symnode));
    assert(new_node != NULL);
    
    copy_attributes(new_node, node);
      
    //Collision probing by linked list, if exist go to next node
    while (node_ref != NULL) {          
        if (node_ref->next == NULL)
            break;
        node_ref = node_ref->next;
    }
    
    if (table->node_ref_array[hashVal] == NULL)
        table->node_ref_array[hashVal] = new_node;
    else
        node_ref->next = new_node;
    
    //should i intern fields here? but then what about struct interns later
    if (is_struct(node->attribute))
        internfields_symtable(node, new_node);
    
    //intern parameter list for function
    if (is_function(node->attribute))
        //internplist_symtable(node, new_node);
    
    table->entries += 1;
    check_tablesize(table);
    
    return new_node;
}

/*NEED TO FIX A LOT OF THINGS HERE: pointer->stringnode_ref->hashcode
  to recalc new hash*/
void realloc_symtable(symtab_ref table) {
    int old_length = table->table_length;
    int new_length = (table->table_length)*2 + 1;
    table->table_length = new_length;
    
    //new_array will replace table array in the stringtable_ref pointer
    symnode_ref *new_array = malloc(new_length * 
                                        sizeof(symnode_ref));
    assert(new_array != NULL);
    memset(new_array, 0, new_length * sizeof(symnode_ref));
    
    //Moving all entries from old table into new table
    for (int i = 0; i < old_length; i++) {
        //Go through all the nodes in the linked list of old table
        symnode_ref old_node_ref = table->node_ref_array[i];
        while (old_node_ref != NULL) {    
            hashcode_t hashVal = (uintptr_t)old_node_ref->strnode_entry % new_length;
            
            symnode_ref new_node_ref = new_array[hashVal];
            
            if (new_array[hashVal] == NULL) {
                new_array[hashVal] = old_node_ref;
                old_node_ref = old_node_ref->next;
                new_array[hashVal]->next = NULL;
                continue;
            }
            
            //Skip filled nodes in the linked list of new table
            while (new_node_ref != NULL) {
                if (new_node_ref->next == NULL)
                    break;
                new_node_ref = new_node_ref->next;
            }
            
            new_node_ref->next = old_node_ref;
            old_node_ref = old_node_ref->next;
            new_node_ref->next->next = NULL;    //sever linked nodes
        }
    }
    
    free (table->node_ref_array);
    
    table->node_ref_array = new_array;
}










