#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "astree.rep.h"
#include "lyutils.h"
#include "auxlib.h"

astree yyparse_astree = NULL;
int scan_linenr = 1;
int scan_offset = 0;
bool scan_echo = false;

struct {
   char **filenames;
   int size;
   int last_filenr;
} filename_stack = {NULL, 0, -1};

char *scanner_filename (int filenr) {
   assert (filename_stack.filenames != NULL);
   return filename_stack.filenames[filenr];
}

void scanner_newfilename (char *filename) {
   assert (filename != NULL);
   if (filename_stack.filenames == NULL) {
      filename_stack.size = 16;
      filename_stack.last_filenr = -1;
      filename_stack.filenames
            = malloc (filename_stack.size * sizeof (char*));
      assert (filename_stack.filenames != NULL);
   }else if (filename_stack.last_filenr == filename_stack.size - 1) {
      filename_stack.size *= 2;
      filename_stack.filenames
            = realloc (filename_stack.filenames,
                       filename_stack.size * sizeof (char*));
      assert (filename_stack.filenames != NULL);
   }
   char *newfilename = strdup (filename);
   assert (newfilename != NULL);
   filename_stack.filenames[++filename_stack.last_filenr]
         = newfilename;
}

void scanner_newline (void) {
   ++scan_linenr;
   scan_offset = 0;
}

void scanner_setecho (bool echoflag) {
   scan_echo = echoflag;
}


void scanner_useraction (void) {
   if (scan_echo) {
      if (scan_offset == 0) printf (";%5d: ", scan_linenr);
      printf ("%s", yytext);
   }
   scan_offset += yyleng;
}

void yyerror (char *message) {
   assert (filename_stack.filenames != NULL);
   errprintf ("%:%s: %d: %s\n",
              filename_stack.filenames[filename_stack.last_filenr],
              scan_linenr, message);
}

void scanner_badchar (unsigned char bad) {
   char char_rep[16];
   sprintf (char_rep, isgraph ((int) bad) ? "%c" : "\\%03o", bad);
   errprintf ("%:%s: %d: invalid source character (%s)\n",
              filename_stack.filenames[filename_stack.last_filenr],
              scan_linenr, char_rep);
}

void scanner_badtoken (char *lexeme) {
   errprintf ("%:%s: %d: invalid token (%s)\n",
              filename_stack.filenames[filename_stack.last_filenr],
              scan_linenr, lexeme);
}

int yylval_token (int symbol) {
    int offset = scan_offset - yyleng;
    yylval = new_astree (symbol, filename_stack.last_filenr,
                        scan_linenr, offset, yytext);
    dump_token();
    return symbol;
}

astree new_parseroot (void) {
    yyparse_astree = new_astree (ROOT, 0, 0, 0, "");
    return yyparse_astree;
}

astree new_function (void) {
    int offset = scan_offset - yyleng;
    return new_astree (TOK_FUNC, filename_stack.last_filenr,
                        scan_linenr, offset, "function");
}    


void scanner_include (void) {
    scanner_newline();
    char *filename = alloca (strlen (yytext) + 1);
    int linenr;
    int scan_rc = sscanf (yytext, "# %d \"%[^\"]\"", &linenr, filename);
    if (scan_rc != 2) {
        errprintf ("%: %d: [%s]: invalid directive, ignored\n",
                 scan_rc, yytext);
    }else {
      char *newfilename = strdup (filename);
      assert (newfilename != NULL);
      fprintf (writeto_tok, "# %d \"%s\"\n", linenr, newfilename);
      scanner_newfilename (newfilename);
      scan_linenr = linenr - 1;
      DEBUGF ('m', "filename=%s, scan_linenr=%d\n",
              filename_stack.filenames[filename_stack.last_filenr],
              scan_linenr);
    }
}

void dump_token(void) {
    fprintf(writeto_tok, "%d%5d.%03d%5d\t%-15s(%s)\n",
        yylval->filenr, yylval->linenr, yylval->offset,
        yylval->symbol, get_yytname(yylval->symbol), 
        peek_stringtable(yylval->lexinfo));
}







