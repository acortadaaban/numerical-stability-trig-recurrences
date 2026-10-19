#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "trigrec.h"

int main (int argc, char *argv[]) {
   int k;
   double x;
   if (argc != 3
         || sscanf(argv[1], "%d", &k) != 1
         || sscanf(argv[2], "%lf", &x) != 1
         ) {
      fprintf(stderr, "Ús: trigrec_escr k x\n");
      return -1;
   }
   
   if (k <= 0) {
      fprintf(stderr, "Error: k ha de ser un enter positiu.\n");
      return -1;
   }
   
   struct coefcs *cfs0 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs1 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs2 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs3 = malloc((k+1) * sizeof(struct coefcs));
   
   if (!cfs0 || !cfs1 || !cfs2 || !cfs3) {
      fprintf(stderr, "Error: no s'ha pogut reservar memòria.\n");
      free(cfs0);
      free(cfs1);
      free(cfs2);
      free(cfs3);
      return -1;
   }
   
   trigrec0(k, x, cfs0);
   trigrec1(k, x, cfs1);
   trigrec2(k, x, cfs2);
   trigrec3(k, x, cfs3);

   for (int j = 0; j <= k; j++) {
      printf("%.16g %.16g %.16g %.16g %.16g %.16g %.16g %.16g\n",
            cfs0[j].c, cfs0[j].s,
            cfs1[j].c, cfs1[j].s,
            cfs2[j].c, cfs2[j].s,
            cfs3[j].c, cfs3[j].s);
   }
   
   free(cfs0);
   free(cfs1);
   free(cfs2);
   free(cfs3);
   
   return 0;
}
