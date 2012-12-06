
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wait.h>
#include <unistd.h>

#include "mylib.h"
#include "astree.rep.h"
#include "lyutils.h"
#include "emission.h"

#define _GNU_SOURCE
#define CPP "/usr/bin/cpp"
#define LINESIZE 1024
#define YYEOF 0

char *progname;
char cpp_opt[50] = "";
int exit_status = EXIT_SUCCESS;
int parsecode = 1;

FILE *writeto_str;
stringtable_ref str_table;

// Print a warning after a failed system call.
void syswarn (char *problem) {
    fflush (NULL);
    fprintf (stderr, "%s: %s: %s\n",
             progname, problem, strerror (errno));
    fflush (NULL);
    exit_status = EXIT_FAILURE;
}

// Chomp the last character from a buffer if it is delim.
void chomp (char *string, char delim) {
    size_t len = strlen (string);
    if (len == 0) return;
    char *nlpos = string + len - 1;
    if (*nlpos == delim) *nlpos = '\0';
}

void scan_opts (int argc, char **argv) {
    int option;
    opterr = 0;

    for(;;) {
        option = getopt (argc, argv, "@:D:ly");
        if (option == EOF) break;
        switch (option) {
         case '@': set_debugflags (optarg);             break;
         case 'D': sprintf(cpp_opt, "-D %s ", optarg);  break;
         case 'l': yy_flex_debug = 1;                   break;
         case 'y': yydebug = 1;                         break;
         default:  errprintf ("%:bad option (%c)\n", optopt); break;
        }
    }
    if (optind > argc) {
        errprintf ("Usage: %s [-ly] [filename]\n", get_execname());
        exit (get_exitstatus());
    }
}

char *yyin_cpp_command = NULL;
void yyin_cpp_open (char *input_file) {
    yyin_cpp_command = malloc(strlen (CPP) + strlen (input_file) + 2);
    strcpy (yyin_cpp_command, CPP);
    strcat (yyin_cpp_command, " ");
    strcat (yyin_cpp_command, cpp_opt);
    strcat (yyin_cpp_command, input_file);
    
    yyin = popen (yyin_cpp_command, "r");
    if (yyin == NULL) {
       syswarn (yyin_cpp_command);
    } else {
       parsecode = yyparse();
    }
}


char *create_file_ext (char *p, char *input_file, char *ext) {
    int len = p-input_file;
    char *outputfile = malloc(len + 5);
    memset(outputfile, 0, len + 5);
    strncpy(outputfile, input_file, len);
    strcat(outputfile, ext);
    return outputfile;
}

int main (int argc, char **argv) {
    yy_flex_debug = 0;
    progname = basename (argv[0]);
    set_execname(argv[0]);
    scan_opts(argc, argv);
    
    char *p;
    char *input_file = argv[optind];
    
    if (input_file == NULL ) {
        errprintf ("Usage: %s [-ly] [-@ flag ...] \
                    [-D string] [filename]\n", 
                    get_execname());
        exit(1);
    }
    
    //Determine file name to write output to
    p = strrchr(input_file, '.');
    
    if (p == NULL || (strncmp(p, ".oc", 128) != 0)) {
       errprintf ("%s: file format not recognized.\n", get_execname());
       exit(1);
    }
    
    //Initialized global variable stringtable
    str_table = new_stringtable();
    
    //Auxiliary functions to make code more modular
    char *outputfile_str = create_file_ext(p, input_file, ".str");
    char *outputfile_tok = create_file_ext(p, input_file, ".tok");
    char *outputfile_ast = create_file_ext(p, input_file, ".ast");
    char *outputfile_oil = create_file_ext(p, input_file, ".oil");
    
    //Create file with .tok extension and write to it. Create
    //even if cpp return fails.
    writeto_tok = fopen(outputfile_tok, "w");
    yyin_cpp_open(input_file);
    
    //if cpp returns successfully, create .str file and .ast file   
    if (exit_status == 0) {
        //create .str file
        writeto_str = fopen(outputfile_str, "w");
        debugdump_stringtable(str_table, writeto_str);
        fclose(writeto_str);
        
        //create .ast file and .oil file
        writeto_ast = fopen(outputfile_ast, "w");
        writeto_oil = fopen(outputfile_oil, "w");
        if (parsecode) {
            errprintf ("%:parse failed (%d)\n", parsecode);
           }
        else {
            global(yyparse_astree);
            global_emission(yyparse_astree);
            dump_astree_format(writeto_ast, yyparse_astree);
        }
        fclose(writeto_ast);
        fclose(writeto_oil);
    }
    
    delete_stringtable(str_table);
    fclose(writeto_tok);
    return parsecode;
}








