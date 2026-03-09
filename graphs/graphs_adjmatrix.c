#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];   // Adjacency matrix
int visited[MAX];
int n;               // Number of vertices

// Function to create adjacency matrix
void createGraph() {
    int i, j, edges, origin, destin;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize all edges to 0
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (origin destination):\n");
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &origin, &destin);
        if (origin >= n || destin >= n || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--;
        } else {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;  // For undirected graph
        }
    }
}

// DFS function (recursive)
void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS function (using queue)
void BFS(int start) {
    int queue[MAX], front = -1, rear = -1;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    front = rear = 0;
    queue[rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// Display adjacency matrix
void displayMatrix() {
    int i, j;
    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main() {
    int choice, start, i;

    do {
        printf("\n\n***** GRAPH MENU *****");
        printf("\n1. Create Graph");
        printf("\n2. Display Adjacency Matrix");
        printf("\n3. DFS Traversal");
        printf("\n4. BFS Traversal");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                for (i = 0; i < n; i++)
                    visited[i] = 0;
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &start);
                printf("DFS Traversal: ");
                DFS(start);
                printf("\n");
                break;

            case 4:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &start);
                printf("BFS Traversal: ");
                BFS(start);
                printf("\n");
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}

