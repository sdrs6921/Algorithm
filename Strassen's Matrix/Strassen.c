#include "stdio.h"
#include "stdlib.h"
#include "Strassen.h"

void Strassen(int n, int **matrix_A, int **matrix_B, int ***matrix_C){
   int i, j;
   if(n <= threshold) Compute(n, matrix_A, matrix_B, matrix_C);
   else{
      int **m1,**m2,**m3,**m4,**m5,**m6,**m7;
      int **a11,**a12,**a21,**a22,**b11,**b12,**b21,**b22,**c11, **c12, **c21, **c22;//for partition A and B
      int **cal1,**cal2;

      a11 = (int**)malloc(sizeof(int*) * n/2);
      a12 = (int**)malloc(sizeof(int*) * n/2);
      a21 = (int**)malloc(sizeof(int*) * n/2);
      a22 = (int**)malloc(sizeof(int*) * n/2);
      b11 = (int**)malloc(sizeof(int*) * n/2);
      b12 = (int**)malloc(sizeof(int*) * n/2);
      b21 = (int**)malloc(sizeof(int*) * n/2);
      b22 = (int**)malloc(sizeof(int*) * n/2);
      c11 = (int**)malloc(sizeof(int*) * n/2);
      c12 = (int**)malloc(sizeof(int*) * n/2);
      c21 = (int**)malloc(sizeof(int*) * n/2);
      c22 = (int**)malloc(sizeof(int*) * n/2);
      m1 = (int**)malloc(sizeof(int*) * n/2);
      m2 = (int**)malloc(sizeof(int*) * n/2);
      m3 = (int**)malloc(sizeof(int*) * n/2);
      m4 = (int**)malloc(sizeof(int*) * n/2);
      m5 = (int**)malloc(sizeof(int*) * n/2);
      m6 = (int**)malloc(sizeof(int*) * n/2);
      m7 = (int**)malloc(sizeof(int*) * n/2);
      cal1 = (int**)malloc(sizeof(int*) * n/2);
      cal2 = (int**)malloc(sizeof(int*) * n/2);

      for(i = 0; i < n; i++){
          a11[i] = (int*)malloc(sizeof(int) * n/2);
          a12[i] = (int*)malloc(sizeof(int) * n/2);
          a21[i] = (int*)malloc(sizeof(int) * n/2);
          a22[i] = (int*)malloc(sizeof(int) * n/2);
          b11[i] = (int*)malloc(sizeof(int) * n/2);
          b12[i] = (int*)malloc(sizeof(int) * n/2);
          b21[i] = (int*)malloc(sizeof(int) * n/2);
          b22[i] = (int*)malloc(sizeof(int) * n/2);
          c11[i] = (int*)malloc(sizeof(int) * n/2);
          c12[i] = (int*)malloc(sizeof(int) * n/2);
          c21[i] = (int*)malloc(sizeof(int) * n/2);
          c22[i] = (int*)malloc(sizeof(int) * n/2);
          m1[i] = (int*)malloc(sizeof(int) * n/2);
          m2[i] = (int*)malloc(sizeof(int) * n/2);
          m3[i] = (int*)malloc(sizeof(int) * n/2);
          m4[i] = (int*)malloc(sizeof(int) * n/2);
          m5[i] = (int*)malloc(sizeof(int) * n/2);
          m6[i] = (int*)malloc(sizeof(int) * n/2);
          m7[i] = (int*)malloc(sizeof(int) * n/2);
          cal1[i] = (int*)malloc(sizeof(int) * n/2);
          cal2[i] = (int*)malloc(sizeof(int) * n/2);
      }

      Partition(n , matrix_A, a11, a12, a21, a22);
      Partition(n , matrix_B, b11, b12, b21, b22);

      matrixSum(n/2,a11,a22,&cal1);
      matrixSum(n/2,b11,b22,&cal2);
      Strassen(n/2,cal1,cal2,&m1);//m1
      matrixSum(n/2,a21,a22,&cal1);
      Strassen(n/2,cal1,b11,&m2);//m2
      matrixSub(n/2,b12,b22,&cal1);
      Strassen(n/2,a11,cal1,&m3);//m3
      matrixSub(n/2,b21,b11,&cal1);
      Strassen(n/2,a22,cal1,&m4);//m4
      matrixSum(n/2,a11,a12,&cal1);
      Strassen(n/2,cal1,b22,&m5);//m5
      matrixSub(n/2,a21,a11,&cal1);
      matrixSum(n/2,b11,b12,&cal2);
      Strassen(n/2,cal1,cal2,&m6);//m6
      matrixSub(n/2,a12,a22,&cal1);
      matrixSum(n/2,b21,b22,&cal2);
      Strassen(n/2,cal1,cal2,&m7);//m7

      /*Compute Strassen*/
      //C11 = M1 + M4 - M5 + M7
      matrixSum(n/2,m1,m4,&cal1);
      matrixSum(n/2,cal1,m7,&cal2);
      matrixSub(n/2,cal2,m5,&c11);
      //C12 = M3 + M5
      matrixSum(n/2,m3,m5,&c12);
      //C21 = M2 + M4
      matrixSum(n/2,m2,m4,&c21);
      //C22 = M1 - M2 + M3 + M6
      matrixSum(n/2,m1,m3,&cal1);
      matrixSum(n/2,cal1,m6,&cal2);
      matrixSub(n/2,cal2,m2,&c22);
      
      for(i = 0; i < n; i++){
         for(j = 0; j < n; j++){
            if(i < n/2 && j < n/2)(*matrix_C)[i][j] = c11[i][j];
            else if(i < n/2 && j >= n/2)(*matrix_C)[i][j] = c12[i][j-n/2];
            else if(i >= n/2 && j < n/2)(*matrix_C)[i][j] = c21[i-n/2][j];
            else (*matrix_C)[i][j] = c22[i-n/2][j-n/2];
         }
      }
   }
}

void Compute(int n, int **matrix_A, int **matrix_B, int ***matrix_C){
   /*Standard Matrix Multiplicant*/
   int i, j, k;
   for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
         (*matrix_C)[i][j] = 0;
         for(k = 0; k < n; k++)
            (*matrix_C)[i][j] =(*matrix_C)[i][j] + matrix_A[i][k] * matrix_B[k][j]; 
      }
   }
}

void Partition(int n, int **matrix, int **subMatrix11, 
      int **subMatrix12,int **subMatrix21,int **subMatrix22){
   /*Partition 4 Matrix*/
   int i , j;
   for(i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
            if(i < n/2 && j < n/2) subMatrix11[i][j] = matrix[i][j];
            else if(i >= n/2 && j < n/2) subMatrix21[i-n/2][j] = matrix[i][j];
            else if(i < n/2 && j >= n/2) subMatrix12[i][j-n/2] = matrix[i][j];
            else subMatrix22[i-n/2][j-n/2] = matrix[i][j];
      }
   }
}

void matrixSum(int n, int **matrix_A, int **matrix_B, int ***matrix_C){
   int i,j;
   for(i = 0; i < n; i++){
       for(j = 0; j < n; j++){
         (*matrix_C)[i][j] = matrix_A[i][j] + matrix_B[i][j];
       }
   }
}

void matrixSub(int n, int **matrix_A, int **matrix_B, int ***matrix_C){
   int i, j;
   for(i = 0; i < n; i++){
       for(j = 0; j < n; j++){
             (*matrix_C)[i][j] = matrix_A[i][j] - matrix_B[i][j];
       }
   }
}

