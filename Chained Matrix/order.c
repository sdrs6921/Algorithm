#include "stdio.h"

extern int **p;

void order(int i, int j){
   int k;
   
   if(i == j) printf("A%d",i+1);
   else{
      k = p[i][j] - 1;
      printf("(");
      order(i,k);
      order(k+1,j);
      printf(")");
   }
}
