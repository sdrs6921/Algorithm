#ifndef __KRUSKAL_H__
#define __KRUSKAL_H__

#define EDGE_NUM 8

typedef struct edge{
   int start;
   int end;
   int weight;
}edge;

void kruskal(int , int , edge* , edge**);

int compare(const void*, const void*);

#endif
