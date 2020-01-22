#include "stdio.h"
#include "stdlib.h"
#include "kruskal.h"
#include "data.h"

int fSize;

int main(void){

   edge e[EDGE_NUM];
   edge *f = (edge*)malloc(sizeof(edge) * EDGE_NUM);
   index i;

   /*initailize set_of_edge*/
   e[0].start = 1;   e[0].end = 2;  e[0].weight = 8;
   e[1].start = 1;   e[1].end = 4;  e[1].weight = 11;
   e[2].start = 2;   e[2].end = 3;  e[2].weight = 7;
   e[3].start = 2;   e[3].end = 4;  e[3].weight = 1;
   e[4].start = 2;   e[4].end = 5;  e[4].weight = 4;
   e[5].start = 3;   e[5].end = 6;  e[5].weight = 5;
   e[6].start = 4;   e[6].end = 5;  e[6].weight = 2;
   e[7].start = 5;   e[7].end = 6;  e[7].weight = 3;

   /*print E set_of_edge*/
   printf("<<Print Set Of Edge E>> \n");
   for(i = 0; i < EDGE_NUM; i++) printf("(v%d,v%d) %d\n",e[i].start,e[i].end,e[i].weight);
   kruskal(ELE_NUM, EDGE_NUM, (edge*)e,&f);
   
   /*print F set_of_edge*/
   printf("<<Print Set Of Edge F>> \n");
   for(i = 0; i < fSize; i++) printf("(v%d,v%d) %d\n",f[i].start,f[i].end,f[i].weight);

   return 0;
}
