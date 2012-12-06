%{
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "lyutils.h"
#include "astree.h"
#include "astree.rep.h"

%}

%debug
%defines
%error-verbose
%token-table
%verbose

%token TOK_VOID TOK_BOOL TOK_CHAR TOK_INT TOK_STRING TOK_NEWSTRING
%token TOK_IF TOK_ELSE TOK_WHILE TOK_RETURN TOK_STRUCT TOK_PARAMLIST
%token TOK_FALSE TOK_TRUE TOK_NULL TOK_NEW TOK_ARRAY TOK_INDEX
%token TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_IDENT TOK_INTCON TOK_CHARCON TOK_STRINGCON TOK_NOTIDENT

%token TOK_BLOCK TOK_CALL TOK_IFELSE TOK_VARDECL TOK_DECLID
%token TOK_POS TOK_NEG TOK_NEWARRAY TOK_TYPEID TOK_FIELD 
%token TOK_ORD TOK_CHR TOK_ROOT TOK_FUNC TOK_PROTOTYPE TOK_RETURNVOID

%token ROOT NUMBER DIGIT FUNCTION

%right  TOK_IF TOK_ELSE
%right  '='
%left   TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%left   '+' '-'
%left   '*' '/' '%'
%right  TOK_POS TOK_NEG '!' TOK_ORD TOK_CHR
%left   '[' '.' TOK_CALL
%nonassoc TOK_NEW
%nonassoc '('

%start program

%%

start    : program                    { yyparse_astree = $1; }
         ;
         
program  : program structdef          { $$ = adopt1 ($1, $2); }
         | program function           { $$ = adopt1 ($1, $2); }
         | program stmt               { $$ = adopt1 ($1, $2); }
         | program error '}'          { $$ = $1; }
         | program error ';'          { $$ = $1; }
         |                            { $$ = new_parseroot (); }
         ;
        
structdef: TOK_STRUCT sd_list '}'     { $$ = adopt1($1, $2); }
         ;
         
sd_list: sd_list fielddecl ';'        { $$ = adopt1($1, $2); }
       | TOK_IDENT '{'                { $1 = changesym($1, TOK_TYPEID);
                                        $$ = $1; }
       ;

function : functionhead ')' block     { if (strcmp(peek_stringtable
                                            ($3->lexinfo), ";") == 0)
                                        $1 = changesym($1, 
                                                       TOK_PROTOTYPE);
                                        $$ = adopt1($1, $3); }
         ;
         
functionhead: identdecl paramlist     { $$ = adopt2(new_function(),
                                                    $1, $2); }
            ;
            
paramlist: paramlist ',' identdecl    { $$ = adopt1($1, $3); }
         | '(' identdecl              { $$ = adopt1sym($1, $2,
                                                       TOK_PARAMLIST);}
         | '('                        { $1 = changesym($1, 
                                                       TOK_PARAMLIST);
                                        $$ = $1; }
         ;

stmt     : block                      { $$ = $1; }
         | vardecl                    { $$ = $1; }
         | while                      { $$ = $1; }
         | ifelse                     { $$ = $1; }
         | return                     { $$ = $1; }
         | expr ';'                   { $$ = $1; }
         ;

block    : stmt_list '}'              { $$ = $1; }
         | ';'                        { $$ = $1; }
         ;
         
stmt_list: '{' stmt                   { $$ = adopt1sym ($1, $2, 
                                                        TOK_BLOCK); }
         | stmt_list stmt             { $$ = adopt1($1, $2); }
         ;
         
ifelse   : TOK_IF '(' expr ')' stmt %prec TOK_ELSE   
                                      { $$ = adopt2($1, $3, $5); }
         | TOK_IF '(' expr ')' stmt TOK_ELSE stmt
                                      { $1 = changesym($1, TOK_IFELSE);
                                        $$ = adopt($1, $3, $5, $7, 
                                                   NULL); }
         ;
                  
return   : TOK_RETURN expr ';'        { $$ = adopt1($1, $2); }
         | TOK_RETURN ';'             { $1 = changesym($1, 
                                                       TOK_RETURNVOID);
                                        $$ = $1; }
         ;
         
while    : TOK_WHILE '(' expr ')' stmt     { $$ = adopt2($1, $3, $5); }
         ;

vardecl  : identdecl '=' expr ';'          { $2 = changesym($2, 
                                                        TOK_VARDECL);
                                             $$ = adopt2($2, $1, $3); }
         ;         

identdecl: basetype TOK_IDENT              { $2 = changesym($2, 
                                                        TOK_DECLID);
                                             $$ = adopt1($1, $2); }
         | basetype TOK_ARRAY TOK_IDENT    { $3 = changesym($3, 
                                                         TOK_FIELD);
                                             $$ = adopt2($1, $2, $3); }
         ;

fielddecl: basetype TOK_IDENT              { $2 = changesym($2, 
                                                        TOK_FIELD);
                                             $$ = adopt1($1, $2); }
         | basetype TOK_ARRAY TOK_IDENT    { $3 = changesym($3, 
                                                         TOK_FIELD);
                                             $$ = adopt2($1, $2, $3); }
         ;

expr     : expr '=' expr                   { $$ = adopt2 ($2, $1, $3);}
         | expr '+' expr                   { $$ = adopt2 ($2, $3, $1);}
         | expr '-' expr                   { $$ = adopt2 ($2, $3, $1);}
         | expr '*' expr                   { $$ = adopt2 ($2, $3, $1);}
         | expr '/' expr                   { $$ = adopt2 ($2, $3, $1);}
         | expr '%' expr                   { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_EQ expr                { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_NE expr                { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_LT expr                { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_LE expr                { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_GT expr                { $$ = adopt2 ($2, $3, $1);}
         | expr TOK_GE expr                { $$ = adopt2 ($2, $3, $1);}
         | '+' expr %prec TOK_POS          { $$ = adopt1sym ($1, $2, 
                                                             TOK_POS);}
         | '-' expr %prec TOK_NEG          { $$ = adopt1sym ($1, $2, 
                                                             TOK_NEG);}
         | '!' expr %prec '!'              { $$ = adopt1 ($1, $2); }
         | TOK_ORD expr                    { $$ = adopt1 ($1, $2); }
         | TOK_CHR expr                    { $$ = adopt1 ($1, $2); }
         | allocator                       { $$ = $1; }
         | call                            { $$ = $1; }
         | variable                        { $$ = $1; }
         | constant                        { $$ = $1; }
         | '(' expr ')'                    { $$ = $2; }
         ; 

allocator: TOK_NEW TOK_IDENT '(' ')'       { $2 = changesym($2, 
                                                      TOK_TYPEID);
                                             $$ = adopt1($1, $2); }
         | TOK_NEW TOK_STRING '(' expr ')' { $1 = changesym($1, 
                                                      TOK_NEWSTRING);
                                             $$ = adopt2($1, $2, $4); }
         | TOK_NEW basetype '[' expr ']'   { $1 = changesym($1, 
                                                      TOK_NEWARRAY);
                                             $$ = adopt2($1, $2, $4); }
         ;

variable : TOK_IDENT                       { $$ = $1; }
         | expr '[' expr ']'               { $2 = changesym($2, 
                                                      TOK_INDEX);
                                             $$ = adopt2($2, $1, $3); }
         | expr '.' TOK_IDENT              { $3 = changesym($3, 
                                                      TOK_FIELD);
                                             $$ = adopt2($2, $1, $3); }
         ;
         
call     : call_list ')'                   { $$ = $1; }
         ;
         
call_list: call_list ',' expr              { $$ = adopt1($1, $3); }
         | TOK_IDENT '(' expr              { $2 = changesym($2, 
                                                              TOK_CALL);
                                             $$ = adopt2($2, $1, $3); }
         | TOK_IDENT '('                   { $$ = adopt1sym($2, $1, 
                                                             TOK_CALL);}
         ;

constant : TOK_INTCON                      { $$ = $1; }
         | TOK_CHARCON                     { $$ = $1; }
         | TOK_STRINGCON                   { $$ = $1; }
         | TOK_FALSE                       { $$ = $1; }
         | TOK_TRUE                        { $$ = $1; }
         | TOK_NULL                        { $$ = $1; }
         ;
                  
basetype : TOK_VOID                        { $$ = $1; }
         | TOK_BOOL                        { $$ = $1; }
         | TOK_CHAR                        { $$ = $1; }
         | TOK_INT                         { $$ = $1; }
         | TOK_STRING                      { $$ = $1; }
         | TOK_IDENT                       { $1 = changesym($1, 
                                                         TOK_TYPEID);
                                             $$ = $1; }
         ;


%%

const char *get_yytname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}




