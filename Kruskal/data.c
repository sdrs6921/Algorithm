#include "data.h"

void makeset (index i) {
   U[i].parent = i+1;
   U[i].depth = 0;
}

set_pointer find (index i) {
   index j;
   j = i;

   while(U[j-1].parent != j) j = U[j-1].parent;

   return j;
}

void merge (set_pointer p, set_pointer q) {
   if(U[p-1].depth == U[q-1].depth){
      U[p].depth += 1;
      U[q-1].parent = p;
   }else if (U[p-1].depth < U[q-1].depth) U[p-1].parent = q;
   else U[q-1].parent = p;
}

bool equal (set_pointer p, set_pointer q) {
   if(p == q) return true;
   else return false;
}

void initial(int n) {
   index i;
   for(i = 0; i < n; i++) makeset(i);
}
