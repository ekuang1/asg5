
// Illustrate the idea of using pointers as uintptr_t values
// for indexing into the symbol hash-stack table.

#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
   char *string;
} *node;

int main (int argc, char **argv) {
   node *pseudo = calloc ((ssize_t) argc, sizeof (node));   //array of pointers
   assert (pseudo != 0);
   for (int argi = 0; argi < argc; ++argi) {                //loop through args
      node new = malloc (sizeof (struct node));
      assert (new != NULL);
      new->string = strdup (argv[argi]);               //entry in ht for every arg 
      assert (new->string);
      pseudo[argi] = new;
   }
   for (int argi = 0; argi < argc; ++argi) {
      node ref = pseudo[argi];
      uintptr_t hashcode = (uintptr_t) ref;            //get address of entry in ht
      printf ("%16p %16" PRIxPTR " %6" PRIdPTR " %6" PRIdPTR
              " %6" PRIdPTR "\n",
              ref, hashcode, hashcode % 31, hashcode % 127,
              hashcode % 511);
   }
   return EXIT_SUCCESS;
}
