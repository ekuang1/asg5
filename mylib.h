#include <stdio.h>
#include "stringtable.h"
#include "astree.h"

extern FILE *yyin;
extern astree yyparse_astree;
extern int yyin_linenr;
extern char *yytext;
extern int yy_flex_debug;
extern int yydebug;
extern int yyleng;
extern FILE* writeto_tok;
extern FILE* writeto_ast;
extern stringtable_ref str_table;
extern FILE* writeto_oil;
