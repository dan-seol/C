#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 5


//1. fillMatrix
void fillMatrix(int matrix[ROWS][COLS]) {

  for(int i = 0; i < ROWS; i++) {
  
    for(int j = 0; j < COLS; j++) {
    
      matrix[i][j] = (rand() % 100) + 1;
    
    }

  }

}

//2. printMatrix
void printMatrix(int matrix[ROWS][COLS]) {

  for(int i = 0; i < ROWS; i++ ) {
  
    for(int j = 0; j < COLS; j++ ) {
    
      printf("%d ", matrix[i][j]);

    }
    
    printf("\n");
  
  }

}

//3. transposeMatrix
void transposeMatrix(int matrix[ROWS][COLS]) {

  int *pm = *matrix;

  for(int i = 0; i < ROWS; i++) {
  
    for(int j = 0; j < i; j++) {
    
     int ij = *(pm + (i * COLS) + j);
     int ji = *(pm + (j * COLS) + i);
     
     *(pm + (i * COLS) + j) = ji;
     *(pm + (j * COLS) + i) = ij; 
    
    }

  }

}

//4. multiplyMatrix
void multiplyMatrix(int m1[2][COLS], int m2[ROWS][COLS], int resultMatrix[ROWS][COLS]) {

  for(int i = 0; i < ROWS; i++) {
  
    for(int j = 0; j < COLS; j++) {
    
      int sum = 0;

      if(i < 2) {
      
        for(int k = 0; k < COLS; k++) {
        
          sum += (m1[i][k] * m2[k][j]);
        
        }

      }
      
      resultMatrix[i][j] = sum;

      }
    
    }

  }

//main
int main() 
{

  int matrix[ROWS][COLS];
  
  fillMatrix(matrix);
  printMatrix(matrix);
  
  transposeMatrix(matrix);
  printMatrix(matrix);

  int matrix2[2][COLS] = {{0,1,2,3,4},{5,6,7,8,9}};
  int matrixResult[ROWS][COLS];

  multiplyMatrix(matrix2, matrix, matrixResult);
  printMatrix(matrixResult);

  return 0;

}
