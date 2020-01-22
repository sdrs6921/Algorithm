#include "stdio.h"
#include "type.h"
#include "optsearchtree.h"

#define NODE_NUM 4

int main(void){
   float p[] = {0.2f ,0.3f , 0.1f, 0.4f};
   float minavg;
   int **r,i,j;

   r = (int**)malloc(sizeof(int*)*(NODE_NUM + 1));

   for(i = 0; i < NODE_NUM+1; i++)
      r[i] = (int*)malloc(sizeof(int*) * (NODE_NUM+1));
   optsearchtree(NODE_NUM,(const float *)p, &minavg, r);

   printf("minavg : %f \n", minavg);
   printf("\n");
   printf("print R array \n");
   for(i = 0; i < NODE_NUM+1; i++){
      for(j= 0; j < NODE_NUM +1; j++){
         printf("%5d",r[i][j]);
      }
      printf("\n");
   }

   return 0;
}
