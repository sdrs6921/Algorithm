#ifndef __STRASSEN_H__
#define __STRASSEN_H__

#define threshold 2
//void Strassen(int n, int (*)[(size_t)(n)], int (*)[(size_t)(n)], int (*)[(size_t)(n)]);
void Strassen(int n, int **, int **, int***);
void Compute(int n, int **, int **, int ***);
//void Partition(int n, int(*)[(size_t)(n)], int(*)[(size_t)(n/2)] , int(*)[(size_t)(n/2)],  int(*)[(size_t)(n/2)],  int(*)[(size_t)(n/2)]);
void Partition(int n, int **, int **, int**, int**,int**);
//void matrixSum(int n, int (*)[(size_t)(n)], int (*)[(size_t)(n)], int (*)[(size_t)(n)]);
//void matrixSub(int n, int (*)[(size_t)(n)], int (*)[(size_t)(n)], int (*)[(size_t)(n)]);
void matrixSum(int n, int**, int**, int***);
void matrixSub(int n, int**,int**,int***);
#endif
