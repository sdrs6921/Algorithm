#include "stdio.h"
#include "floyd2.h"
#include "stdlib.h"
#include "path.h"

#define NODE_NUM 5
#define INFINITE 9999999

int **p;

int main(void){
   int **d,i,j,**tmp;
   const int **w; 
   
   d = (int**)malloc(sizeof(int*) * NODE_NUM);
   p = (int**)malloc(sizeof(int*) * NODE_NUM);
   tmp = (int**)malloc(sizeof(int*) *NODE_NUM);

   for(i = 0; i < NODE_NUM; i++){
      d[i] = (int*)malloc(sizeof(int) * NODE_NUM);
      p[i] = (int*)malloc(sizeof(int) * NODE_NUM);
      tmp[i] = (int*)malloc(sizeof(int) * NODE_NUM);
   }

   /*Intialize Graph*/
   tmp[0][0] = 0; tmp[0][1] = 4; tmp[0][2] = INFINITE; tmp[0][3] = 3; tmp[0][4] = 5;
   tmp[1][0] = INFINITE; tmp[1][1] = 0; tmp[1][2] = 1; tmp[1][3] = 2; tmp[1][4] = INFINITE;
   tmp[2][0] = INFINITE; tmp[2][1] = 9; tmp[2][2] = 0; tmp[2][3] = 7; tmp[2][4] = INFINITE;
   tmp[3][0] = 6; tmp[3][1] = INFINITE; tmp[3][2] = 4; tmp[3][3] = 0; tmp[3][4] = INFINITE;
   tmp[4][0] = 10; tmp[4][1] = INFINITE; tmp[4][2] = INFINITE; tmp[4][3] = 4; tmp[4][4] = 0;

   w =(const int**)tmp;//copy to W Matrix

   printf("<<W Array>> \n");
   for(i = 0; i < NODE_NUM; i++){
      for(j = 0; j < NODE_NUM; j++){
         if(w[i][j] != INFINITE) printf("%4d",w[i][j]);
         else printf("  IN");
      }
      printf("\n");
   }

   floyd2(NODE_NUM ,w ,d ,p);

   printf("<<P Array >> \n");
   for(i = 0; i < NODE_NUM; i++){
      for(j = 0; j < NODE_NUM; j++){
         printf("%4d",p[i][j]);
      }
      printf("\n");
   }
   printf("\n");
   printf("Print Path : ");
   all_path(5,2);
   printf("\n");
   return 0;
}
