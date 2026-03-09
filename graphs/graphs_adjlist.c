#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for Graph
struct Graph {
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

// Structure for Queue (used in BFS)
struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Function to create a node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
	int i;
    for ( i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (Undirected Graph)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    printf("\n--- Adjacency List Representation ---\n");
    int v;
    for ( v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->adjLists[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Queue operations
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1)
        return;
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    int item;
    if (isEmpty(q))
        return -1;
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
    return item;
}

// BFS Traversal
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* q = createQueue();
	int i;
    for ( i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;

    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// DFS Traversal (Recursive)
void DFS(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjLists[vertex];

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp) {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
            DFS(graph, connectedVertex);
        temp = temp->next;
    }
}

void resetVisited(struct Graph* graph) {
	int i;
    for ( i = 0; i < graph->numVertices; i++)
        graph->visited[i] = 0;
}

// Main program with menu
int main() {
    int vertices, choice, src, dest, startVertex;
    struct Graph* graph = NULL;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    graph = createGraph(vertices);

    while (1) {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. BFS Traversal\n");
        printf("4. DFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter source and destination vertex: ");
            scanf("%d %d", &src, &dest);
            if (src >= vertices || dest >= vertices || src < 0 || dest < 0)
                printf("Invalid vertices!\n");
            else
                addEdge(graph, src, dest);
            break;

        case 2:
            printGraph(graph);
            break;

        case 3:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &startVertex);
            if (startVertex >= vertices)
                printf("Invalid vertex!\n");
            else
                BFS(graph, startVertex);
            break;

        case 4:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &startVertex);
            if (startVertex >= vertices)
                printf("Invalid vertex!\n");
            else {
                resetVisited(graph);
                printf("DFS Traversal: ");
                DFS(graph, startVertex);
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

