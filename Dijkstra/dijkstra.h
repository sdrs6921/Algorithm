#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#define NODE_NUM 5
#define INFINITE 999999999

typedef int index;
typedef int number;

typedef struct edge{
   int start,end,weight;
}edge;

void dijkstra(int, const int**, edge**);

#endif
