#include "attributes.h"

const bitset_t ATTR_VOID     = 1 << ATTR_INDEX_VOID;
const bitset_t ATTR_BOOL     = 1 << ATTR_INDEX_BOOL;
const bitset_t ATTR_CHAR     = 1 << ATTR_INDEX_CHAR;
const bitset_t ATTR_INT      = 1 << ATTR_INDEX_INT;
const bitset_t ATTR_NULL     = 1 << ATTR_INDEX_NULL;
const bitset_t ATTR_STRING   = 1 << ATTR_INDEX_STRING;
const bitset_t ATTR_STRUCT   = 1 << ATTR_INDEX_STRUCT;
const bitset_t ATTR_ARRAY    = 1 << ATTR_INDEX_ARRAY;
const bitset_t ATTR_FUNCTION = 1 << ATTR_INDEX_FUNCTION;
const bitset_t ATTR_VARIABLE = 1 << ATTR_INDEX_VARIABLE;
const bitset_t ATTR_FIELD    = 1 << ATTR_INDEX_FIELD;
const bitset_t ATTR_TYPEID   = 1 << ATTR_INDEX_TYPEID;
const bitset_t ATTR_PARAM    = 1 << ATTR_INDEX_PARAM;
const bitset_t ATTR_LVALUE   = 1 << ATTR_INDEX_LVALUE;
const bitset_t ATTR_CONST    = 1 << ATTR_INDEX_CONST;
const bitset_t ATTR_VREG     = 1 << ATTR_INDEX_VREG;
const bitset_t ATTR_VADDR    = 1 << ATTR_INDEX_VADDR;

bitset_t bitset (int attribute_index) {
   return 1L << attribute_index;
}

bool is_reference (bitset_t attributes) {
   return attributes
          & (ATTR_NULL | ATTR_STRING | ATTR_STRUCT | ATTR_ARRAY)
       && true;
}

bool is_int (bitset_t attributes) {
    return attributes
           & ATTR_INT && ! (attributes & ATTR_ARRAY);
}

bool is_bool (bitset_t attributes) {
    return attributes
           & ATTR_BOOL && ! (attributes & ATTR_ARRAY);
}

bool is_char (bitset_t attributes) {
    return attributes
           & ATTR_CHAR && ! (attributes & ATTR_ARRAY);
}

bool is_string (bitset_t attributes) {
    return attributes
           & ATTR_STRING && ! (attributes & ATTR_ARRAY);
}

bool is_struct (bitset_t attributes) {
    return attributes & ATTR_STRUCT;
}

bool is_array (bitset_t attributes) {
    return attributes & ATTR_ARRAY;
}

bool is_function (bitset_t attributes) {
    return attributes & ATTR_FUNCTION;
}

bool is_field (bitset_t attributes) {
    return attributes & ATTR_FIELD;
}

bool is_lvalue (bitset_t attributes) {
    return attributes
           & ATTR_LVALUE && ! (attributes & ATTR_ARRAY);
}


/*
//buggy
bool is_sametype (bitset_t attr1, bitset_t attr2) {
    return attr1 & attr2;
}
*/

bool is_primitive (bitset_t attr1, bitset_t attr2) {
    return (is_int(attr1) && is_int(attr2))   ||
           (is_bool(attr1) && is_bool(attr2)) ||
           (is_char(attr1) && is_char(attr2)) ;
}


bool is_anytype (bitset_t attr1, bitset_t attr2) {
    return is_primitive(attr1, attr2)             ||
           (is_string(attr1) && is_string(attr2)) ||
           (is_struct(attr1) && is_struct(attr2)) ||
           (is_array(attr1) && is_array(attr2))   ;
}













// The following initialization style is a gcc-ism and will
// not work with some C compilers, and confuses lint.
const char *attr_names[] = {
   [ATTR_INDEX_VOID    ] "void"    ,
   [ATTR_INDEX_BOOL    ] "bool"    ,
   [ATTR_INDEX_CHAR    ] "char"    ,
   [ATTR_INDEX_INT     ] "int"     ,
   [ATTR_INDEX_NULL    ] "null"    ,
   [ATTR_INDEX_STRING  ] "string"  ,
   [ATTR_INDEX_STRUCT  ] "struct"  ,
   [ATTR_INDEX_ARRAY   ] "array"   ,
   [ATTR_INDEX_FUNCTION] "function",
   [ATTR_INDEX_VARIABLE] "variable",
   [ATTR_INDEX_FIELD   ] "field"   ,
   [ATTR_INDEX_TYPEID  ] "typeid"  ,
   [ATTR_INDEX_PARAM   ] "param"   ,
   [ATTR_INDEX_LVALUE  ] "lvalue"  ,
   [ATTR_INDEX_CONST   ] "const"   ,
   [ATTR_INDEX_VREG    ] "vreg"    ,
   [ATTR_INDEX_VADDR   ] "vaddr"   ,
};

void print_attributes (bitset_t attributes, FILE* out) {
   ssize_t size = sizeof attr_names / sizeof *attr_names;
   for (int index = 0; index < size; ++index) {
      if (attributes & bitset (index)) {
         fprintf (out, " %s", attr_names [index]);
      }
   }
   fprintf(out, "\n");
}




