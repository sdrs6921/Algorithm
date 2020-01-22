#ifndef __DATA_H__
#define __DATA_H__

#define ELE_NUM 6

typedef int index;
typedef index set_pointer;

typedef int bool;
#define TRUE 1
#define FALSE 0

#define true 1
#define false 0

typedef struct node{
   index parent;
   int depth;
}node;


typedef node universe[ELE_NUM];

universe U;

void makeset(index);
set_pointer find (index);
void merge(set_pointer, set_pointer);
bool equal(set_pointer, set_pointer);
void initial(int);

#endif
