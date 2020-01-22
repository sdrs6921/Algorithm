#include "dijkstra.h"
#include "stdio.h"
#include "stdlib.h"

void dijkstra(int n, const int** w, edge** f) {
   index i,j,vnear;
   edge e;
   index *touch;
   number *length, min;
   
   touch = (index*)malloc(sizeof(index)*n);
   length = (number*)malloc(sizeof(length)*n);

   /*Initialize touch, length Array*/
   for(i = 1; i < n; i++){
      touch[i] = 1;
      length[i] = w[0][i];
   }
   
   for(i = 0; i < n-1; i++){
      min = INFINITE;
      for(j = 1; j < n; j++){
         if(length[j]>= 0 && length[j] < min){
            min = length[j];
            vnear = j;
         }
      }

      //Add edge From touch[vnear] to vnear
      (*f)[i].start = touch[vnear];
      (*f)[i].end = vnear + 1;
      (*f)[i].weight = w[touch[vnear]-1][vnear];
      
      for(j = 1; j < n; j++){
         if(length[vnear] + w[vnear][j] < length[j]){
            length[j] = length[vnear] + w[vnear][j];
            touch[j] = vnear + 1;
         }
      }
      length[vnear] = -1;
   }

}
