#include "stdio.h"
#include "stdlib.h"
#include "dijkstra.h"


int main(void){
   int **w;
   index i ,j;
   edge *f;
   w = (int**)malloc(sizeof(int*) * NODE_NUM);
   for(i = 0; i < NODE_NUM; i++)
      w[i] = (int*)malloc(sizeof(int) * NODE_NUM);
   f = (edge*)malloc(sizeof(edge) * NODE_NUM);

   /*Initialize W array*/
   w[0][0] = 0;        w[0][1] = 2;        w[0][2] = 4;        w[0][3] = 3;        w[0][4] = INFINITE;
   w[1][0] = INFINITE; w[1][1] = 0;        w[1][2] = 9;        w[1][3] = INFINITE; w[1][4] = 6;
   w[2][0] = INFINITE; w[2][1] = INFINITE; w[2][2] = 0;        w[2][3] = INFINITE; w[2][4] = INFINITE;
   w[3][0] = INFINITE; w[3][1] = INFINITE; w[3][2] = INFINITE; w[3][3] = 0;        w[3][4] = 7;
   w[4][0] = INFINITE; w[4][1] = INFINITE; w[4][2] = 1;        w[4][3] = INFINITE; w[4][4] = 0;

   printf("<<Print W Array>>\n");
   for(i = 0; i < NODE_NUM; i++){
      for(j = 0; j < NODE_NUM; j++){
         if(w[i][j] == INFINITE) printf("  INF");
         else printf("%5d",w[i][j]);
      }
      printf("\n");
      printf("\n");
   }

   dijkstra(NODE_NUM, (const int**)w , &f);

   printf("<<Print F Edge Set>>\n");
   for(i = 0; i < NODE_NUM-1; i++) printf("(v%d->v%d) weight : %d \n",f[i].start,f[i].end,f[i].weight);
                                
   return 0;
}
