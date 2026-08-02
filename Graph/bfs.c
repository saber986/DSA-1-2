#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int graph[MAX][MAX], int start, int vertices) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    int graph[MAX][MAX] = {0};

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

    bfs(graph, 0, vertices);

    return 0;
}
