#include "stdio.h"
#include "stdlib.h"
#include "minmult.h"

int minmult(int n, const int *d, int **p){
   int i,j,k,diagonal,**m;

   /*create M array*/
   m = (int **)malloc(sizeof(int*) * n);
   for (i = 0; i < n; i++)
      m[i] = (int*)malloc(sizeof(int) * n);

   for(i = 0; i < n; i++)  m[i][i] = 0;

   for(diagonal = 0; diagonal < n-1; diagonal++){
      for(i = 0; i < n-diagonal-1; i++){
         j = i + diagonal + 1;
         m[i][j] = minimum((const int)i,(const int)j, d ,m , &p);
      }
   }

   printf("\n");
   printf("<<M Array>> \n");
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         printf("%5d",m[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   return m[0][n-1];
}

int minimum(const int i, const int j, const int *d , int **m, int***p){
   int res, k;
   res = MAX_NUM;
   for(k = i; k < j; k++){
      if(res >= m[i][k] + m[k+1][j] + d[i]*d[k+1]*d[j+1]){
         res = m[i][k] + m[k+1][j] + d[i]*d[k+1]*d[j+1];
         (*p)[i][j] = k + 1;
      }
   }
   return res;
}
