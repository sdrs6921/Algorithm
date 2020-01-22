#include "stdio.h"
#include "stdlib.h"
#include "Strassen.h"

#define MAT_LEN 4

int main(void)
{
   int i,j;

   int **a = (int **)malloc(sizeof(int*) * MAT_LEN);
   int **b = (int **)malloc(sizeof(int*) * MAT_LEN);
   int **c = (int **)malloc(sizeof(int*) * MAT_LEN);
   
   for(i = 0; i < MAT_LEN; i++){
      a[i] = (int *)malloc(sizeof(int) * MAT_LEN);
      b[i] = (int *)malloc(sizeof(int) * MAT_LEN);
      c[i] = (int *)malloc(sizeof(int) * MAT_LEN);
   }

   a[0][0] = 2;
   a[0][1] = 3;
   a[0][2] = 7;
   a[0][3] = 8;
   a[1][0] = 1;
   a[1][1] = 3;
   a[1][2] = 5;
   a[1][3] = 8;
   a[2][0] = 11;
   a[2][1] = 2;
   a[2][2] = 5;
   a[2][3] = 6;
   a[3][0] = 9;
   a[3][1] = 3;
   a[3][2] = 5;
   a[3][3] = 7;

   
   b[0][0] = 4;
   b[0][1] = 5;
   b[0][2] = 6;
   b[0][3] = 2;
   b[1][0] = 3;
   b[1][1] = 1;
   b[1][2] = 2;
   b[1][3] = 5;
   b[2][0] = 4;
   b[2][1] = 7;
   b[2][2] = 1;
   b[2][3] = 5;
   b[3][0] = 6;
   b[3][1] = 8;
   b[3][2] = 11;
   b[3][3] = 2;

   printf("A matrix \n");
   for(i = 0; i < MAT_LEN; i++){
      for(j = 0; j < MAT_LEN; j++){
         printf("%4d",a[i][j]);
      }
      printf("\n");
   }

   printf("B matrix \n");
   for(i = 0; i < MAT_LEN; i++){
      for(j = 0; j < MAT_LEN; j++){
         printf("%4d",b[i][j]);
      }
      printf("\n");
   }


   Strassen(MAT_LEN , a, b, &c);

   printf("C matrix \n");
   for(i = 0; i < MAT_LEN; i++){
      for(j = 0; j < MAT_LEN; j++){
         printf("%4d", c[i][j]);
      }
      printf("\n");
   }
   return 0;
}
