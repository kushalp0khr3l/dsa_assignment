#include <stdio.h>

#define MAX 5
int adj[MAX][MAX];
int visited[MAX];
int n = 5;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void DFS(int v) {
    printf("%d ", v);
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    int visited_bfs[MAX] = {0};

    visited_bfs[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited_bfs[i]) {
                visited_bfs[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    printf("DFS (Goes deep first): ");
    DFS(0);
    
    printf("\nBFS (Goes broad first): ");
    BFS(0);
    printf("\n");

    return 0;
}