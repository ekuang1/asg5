#ifndef __ASTREEREP_H__
#define __ASTREEREP_H__

#include <inttypes.h>
#include "astree.h"
#include "stringtable.h"
#include "sym_tab.h"

typedef uint64_t bitset_t;

struct astree_rep {
   char *tag;                 // tag field to verify class membership
   int symbol;                // token code
   int filenr;                // index into filename stack
   int linenr;                // line number from source code
   int offset;                // offset of token with current line
   stringnode_ref lexinfo;    // pointer to lexical information
   astree first;              // first child node of this node
   astree last;               // last child node of this node
   astree next;               // next younger sibling of this node
   bitset_t attribute;        // attributes of node
   int blockno;               // scoping
   char *blockstruct;
   symnode_ref struct_node;
   char vreg[25];
};


#endif

