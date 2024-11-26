#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];     // Visited array

void BFS(int start, int vertices) {
    int queue[MAX], front = 0, rear = 0;
    int i;

    // Initialize visited array to 0 (false)
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%c ", 'A' + node);

        for (i = 0; i < vertices; i++) {
            if (adj[node][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSUtil(int node, int vertices) {
    int i;
    visited[node] = 1;
    printf("%c ", 'A' + node);

    for (i = 0; i < vertices; i++) {
        if (adj[node][i] && !visited[i]) {
            DFSUtil(i, vertices);
        }
    }
}

void DFS(int start, int vertices) {
    int i;

    // Initialize visited array to 0 (false)
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    printf("DFS Order: ");
    DFSUtil(start, vertices);
    printf("\n");
}

int main() {
    int vertices = 7;
    // clrscr();
    // Initialize adjacency matrix to 0
    memset(adj, 0, sizeof(adj));

    // Define the graph's adjacency matrix (Example graph)
    adj[0][1] = adj[0][2] = 1;
    adj[1][3] = adj[1][4] = 1;
    adj[2][5] = adj[2][6] = 1;

    printf("Graph Traversal:\n");
    BFS(0, vertices);
    DFS(0, vertices);
    // getch();
    return 0;
}
