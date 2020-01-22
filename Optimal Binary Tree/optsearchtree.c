#include "stdio.h"
#include "stdlib.h"
#include "optsearchtree.h"

void optsearchtree(int n, const float *p, float *minavg, int**r){
   int i,j,k,diagonal;
   float **a;

   a = (float**)malloc(sizeof(float*) * (n+1));
   for(i = 0; i < n+1; i++) 
      a[i] = (float*)malloc(sizeof(float) * (n+1));

   for(i = 0; i < n; i++){
      a[i][i] = 0;
      r[i][i] = 0;
      a[i][i+1] = p[i];
      r[i][i+1] = i + 1;
   }

   a[n][n-1] = 0;
   r[n][n-1] = 0;

   for(diagonal = 1; diagonal < n; diagonal++)
      for(i = 0; i< n-diagonal; i++){
         j = i+diagonal+1;
         a[i][j] = minimum(i,j,a,&r) + sigma(i, j, p);
      }

   *minavg = a[0][n];

   printf("<<print A array>> \n");
   for(i = 0; i < n+1; i++){
      for(j = 0; j < n+1; j++){
         printf("%5f \t",a[i][j]);
      }
      printf("\n");
      printf("\n");
   }
}

float minimum(int i, int j, float**a, int***r){
   float res = MAX_NUM;
   int k;

   for (k = i; k < j; k++){
      if(res > a[i][k] + a[k+1][j]){
         res = a[i][k] + a[k+1][j];
         (*r)[i][j] = k + 1;
      }
   }
   return res;
}

float sigma(int i,int j,const float *p){
   int m;
   float res = 0;
   for(m = i; m < j; m++){
      res += p[m];
   }
}
