#include <stdio.h>
#include <stdlib.h>

int ** createMatrix(int n);
void readEdges(int ** matrix, int n, int m);
void printMatrix(int ** matrix, int n);

int main() {

  int m, n;

  printf("Enter the number of vertices(n) and edges(m): ");
  scanf("%d %d", &n, &m);

  int ** matrix = createMatrix(n);
  readEdges(matrix, n, m);
  printMatrix(matrix, n);

  return 0;

}

int ** createMatrix(int n) {

  int i, j;
  int ** matrix = (int **) malloc((n + 1) * sizeof(int *));

  for(i = 0; i <= n; i++) {
    matrix[i] = (int *) malloc((n + 1) * sizeof(int));
    for(j = 0; j <= n; j++) {
      matrix[i][j] = 0;
    }
  }

  return matrix;

}

void readEdges(int ** matrix, int n, int m) {

  int u, w;

  for (int i = 0; i < m; i++) {
    printf("Enter the vertices of the edge => ");
    scanf("%d %d", &u, &w);
    while(u > n || w > n){
      printf("Enter valid vertices. \n");
      printf("Enter the vertices of the edge => ");
      scanf("%d %d", &u, &w);
    }
    matrix[u][w] = 1;
    matrix[w][u] = 1;
  }

}

void printMatrix(int ** matrix, int n) {

  printf("------------------------\n");

  int i, j;

  for(i = 1; i <= n; i++) {
    if(i == 1){
      printf("     ");
      for(j = 1; j <= n; j++) {
        printf("%d ", j);
      }
    }
    printf("\n%d => ", i);
    for(j = 1; j <= n; j++) {
      printf("%d ", matrix[i][j]);
    }
  }

  printf("\n------------------------\n");

}
