#include "stdio.h"
#include "kruskal.h"
#include "data.h"
#include "stdlib.h"

extern int fSize;

void kruskal(int n, int m, edge* e, edge** f){
   index i,j,a=0,b=0;
   set_pointer p,q;
   edge tmp;

   //sort edge set
   edge E[EDGE_NUM];
   for(i = 0; i < EDGE_NUM; i++){
      E[i].start = e[i].start;
      E[i].end = e[i].end;
      E[i].weight = e[i].weight;
   }
   qsort(E,sizeof(E)/sizeof(edge),sizeof(edge),compare);
   printf("<<Print Set Of Sorted Edge E>> \n");
   for(i = 0; i < EDGE_NUM; i++) printf("(v%d,v%d) %d\n",E[i].start,E[i].end,E[i].weight);

   //initial
   initial(n);

   while(a < m){
      tmp = E[a++];
      i = tmp.start; j = tmp.end;
      p = find(i); q = find(j);
      if(!equal(p,q)){
         merge(p,q); 
         (*f)[b++] = tmp;
      }

      if(b == n-1){
         break;
      }
   }

   fSize = b;

}

int compare(const void *a, const void *b){
   edge *m = (edge *)a;
   edge *n = (edge *)b;

   if(m->weight < n->weight) return -1;
   else if(m->weight > n->weight) return 1;
   else return 0;
}


