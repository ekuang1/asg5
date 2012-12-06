#ifndef __SYMTAB_H__
#define __SYMTAB_H__

#include "stringtable.h"
#include "astree.h"



typedef struct blockno_stack *blockno_stack_ref;
typedef struct ident_stack *ident_stack_ref;
typedef struct symtab *symtab_ref;
typedef struct symnode *symnode_ref;


symtab_ref sym_table;
symtab_ref struct_table;
blockno_stack_ref blockno_stack;
ident_stack_ref ident_stack;


int symtab_blockno (symnode_ref entry);

blockno_stack_ref new_blockno_stack (void);
symtab_ref new_symtab (void);
void enter_block (blockno_stack_ref t);
void exit_block (void);
int  get_blockno (blockno_stack_ref t);
bool check_table (astree node);
void push_ident_stack (symnode_ref entry);
void remove_ident_symtable(symnode_ref sym_node);
cstring peek_symtable(symnode_ref node_ref);

symnode_ref intern_symtable(symtab_ref table, astree node);
void realloc_symtable(symtab_ref table);

#endif
