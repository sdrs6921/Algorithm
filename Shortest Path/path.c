#include "stdio.h"

extern int **p;

void path(int q, int r){
   if(p[q-1][r-1] != 0){
      path(q-1,p[q-1][r-1]);
      printf("V%d->",p[q-1][r-1]);
      path(p[q-1][r-1],r-1);
   }
}

void all_path(int q, int r){
   printf("V%d->", q);
   path(q,r);
   printf("V%d",r);
}
