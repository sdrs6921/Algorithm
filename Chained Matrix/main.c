#include "stdio.h"
#include "stdlib.h"
#include "minmult.h"
#include "order.h"

#define MAT_SIZE 5

int **p;

int main(void){
   int i,j,minimum;
   int d[] = {3,4,6,2,7,4};

   p = (int**)malloc(sizeof(int*)*(MAT_SIZE));

   for(i = 0; i < MAT_SIZE; i++)
      p[i] = (int*)malloc(sizeof(int)*(MAT_SIZE));
   
   printf("Minimum Value : %d \n",minmult(MAT_SIZE, (const int*)d, p));
   printf("\n");


   printf("<<Print pArray>> \n");
   for(i = 0; i < MAT_SIZE; i++){
      for(j = 0; j < MAT_SIZE; j++){
         printf("%5d",p[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   printf("Print Minimum Order : ");
   order(0,MAT_SIZE -1);
   printf("\n");
   return 0;
}
