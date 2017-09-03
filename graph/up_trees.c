#include <stdio.h>
#include <stdlib.h>

void initializeGraph(int n);
void readGraph(int n);
int searchVertice(int p);
void joinVertices(int p, int q);

int * graph;

int main(void) {
  initializeGraph(7);
  joinVertices(3, 5);
  readGraph(7);
  joinVertices(7, 4);
  readGraph(7);
  joinVertices(1, 3);
  readGraph(7);
  joinVertices(6, 4);
  readGraph(7);
  joinVertices(4, 2);
  readGraph(7);
  joinVertices(7, 3);
  readGraph(7);
  joinVertices(6, 7);
  readGraph(7);
  for (int i = 1; i <= 7; i++) {
    printf("------ Searching[%d] ------", i);
    searchVertice(i);
    readGraph(7);
  }

  return 0;
}

void initializeGraph(int n) {

  graph = calloc(n + 1, sizeof(int));

  for (int i = 1; i <= n; i++) {
    graph[i] = i;
  }

}

int searchVertice(int p){
  if(graph[p] != p){
    graph[p] = searchVertice(graph[p]);
  }
  return graph[p];
}

void joinVertices(int p, int q) {
  searchVertice(p);
  searchVertice(q);
  if(graph[p] > graph[q]){
    graph[graph[p]] = graph[q];
  } else {
    graph[graph[q]] = graph[p];
  }
}

void readGraph(int n) {

  printf("------------------------\n");

  for (int i = 1; i <= n; i++) {
    printf("Father[%d] = %d\n", i, graph[i]);
  }

}
