#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "trigrec.h"
#include "time.h"
#include <time.h>

clock_t t1, t2;
double temps;
int main (int argc, char *argv[])
{
   int k;
   double x;
   if (argc != 3
         || sscanf(argv[1], "%d", &k) != 1
         || sscanf(argv[2], "%lf", &x) != 1
         ) {
      return -1;
   }
   if (k <= 0) {
      return -1;
   }
   
   struct coefcs *cfs0 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs1 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs2 = malloc((k+1) * sizeof(struct coefcs));
   struct coefcs *cfs3 = malloc((k+1) * sizeof(struct coefcs));
   if (!cfs0 || !cfs1 || !cfs2 || !cfs3) {
      fprintf(stderr, "Error: no s'ha pogut reservar memòria.\n");
      free(cfs0); free(cfs1); free(cfs2); free(cfs3);
      return -1;
   }
   //temps Alg0
   t1 = clock();
   trigrec0(k, x, cfs0);
   t2 = clock();
   temps = ((double)(t2-t1))/CLOCKS_PER_SEC;
   printf("trigrec0 triga %.16g segons \n",temps);

   //temps Alg1
   t1 = clock();
   trigrec1(k, x, cfs1);
   t2 = clock();
   temps = ((double)(t2-t1))/CLOCKS_PER_SEC;
   printf("trigrec1 triga %.16g segons \n",temps);

   //temps Alg2
   t1 = clock();
   trigrec2(k, x, cfs2);
   t2 = clock();
   temps = ((double)(t2-t1))/CLOCKS_PER_SEC;
   printf("trigrec2 triga %.16g segons \n",temps);

   //temps Alg3
   t1 = clock();
   trigrec3(k, x, cfs3);
   t2 = clock();
   temps = ((double)(t2-t1))/CLOCKS_PER_SEC;
   printf("trigrec3 triga %.16g segons \n",temps);
   
   double errc1 = 0.0, errc2 = 0.0, errc3 = 0.0;
   double errs1 = 0.0, errs2 = 0.0, errs3 = 0.0;
   for (int j = 0; j <= k; j++) {
      double diff;
      diff = fabs(cfs1[j].c - cfs0[j].c);
      if (diff > errc1) errc1 = diff;
      diff = fabs(cfs2[j].c - cfs0[j].c);
      if (diff > errc2) errc2 = diff;
      diff = fabs(cfs3[j].c - cfs0[j].c);
      if (diff > errc3) errc3 = diff;
      
      diff = fabs(cfs1[j].s - cfs0[j].s);
      if (diff > errs1) errs1 = diff;
      diff = fabs(cfs2[j].s - cfs0[j].s);
      if (diff > errs2) errs2 = diff;
      diff = fabs(cfs3[j].s - cfs0[j].s);
      if (diff > errs3) errs3 = diff;
   }

   printf("\nErrors màxims respecte al mètode 0:\n");
   printf("  errc1 = %f, errc2 = %f, errc3 = %f\n", errc1, errc2, errc3); 
   printf("  errs1 = %f, errs2 = %f, errs3 = %f\n", errs1, errs2, errs3);
   

   free(cfs0);
   free(cfs1);
   free(cfs2);
   free(cfs3);
   
   return 0;
}
