#ifndef __TYPE_H__
#define __TYPE_H__
#include "stdio.h"
#include "malloc.h"

struct node {
   char key;
   struct node *left;
   struct node *right;
};
#endif
