#include "stdio.h"

void floyd2(int n, const int**w, int **d, int **p){
   int i,j,k,a,b;

   for(i = 0; i < n; i++)
      for(j = 0; j < n; j++)
         p[i][j] = 0;

   d =(int**)w;
   
   
   for(k = 0; k < n; k++){
      for(i = 0; i < n; i++){
         for(j = 0; j < n; j++)
            if(d[i][k] + d[k][j] < d[i][j]){
               p[i][j] = k + 1;
               d[i][j] = d[i][k] + d[k][j];
            }
      }
   }


   printf("<<D Array>> \n");
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         printf("%4d",d[i][j]);
      }
      printf("\n");
   }
}
