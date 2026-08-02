#include <stdio.h>

#define MAX 20

void dfs(int graph[MAX][MAX], int visited[], int current, int vertices) {
    printf("%d ", current);
    visited[current] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[current][i] == 1 && visited[i] == 0) {
            dfs(graph, visited, i, vertices);
        }
    }
}

int main() {
    int vertices = 6;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;
    graph[2][0] = 1;
    graph[2][4] = 1;
    graph[3][1] = 1;
    graph[3][5] = 1;
    graph[4][1] = 1;
    graph[4][2] = 1;
    graph[4][5] = 1;
    graph[5][3] = 1;
    graph[5][4] = 1;

    printf("DFS Traversal: ");
    dfs(graph, visited, 0, vertices);
    printf("\n");

    return 0;
}
