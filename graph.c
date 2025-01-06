#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

// Node structure to represent vertex and edges
typedef struct node {
    int data;
    int status;
    struct node *next, *point;
} node;

// Structure for the topological sort order
typedef struct topsort {
    int n;
    struct topsort *next;
} topsort;

int d[SIZE], f[SIZE], time;  // Arrays for discovery and finishing times
node *q[SIZE];               // Queue for BFS
int front = 0, rear = 0;     // Queue pointers
node *g = NULL;              // Graph head
topsort *tsort = NULL;       // Topological sort head

// Function to add a vertex to the graph
void addvertex(int n) {
    node *t = (node*)malloc(sizeof(node));
    t->data = n;
    t->point = NULL;
    t->next = g;
    g = t;
}

// Function to find a vertex node by data
node* find(int n) {
    node *t = g;
    while(t != NULL && t->data != n)
        t = t->next;
    return t;
}

// Function to add an edge between two vertices
void addedge(int u, int v) {
    node *v1 = find(u), *v2 = find(v), *t;
    if (!v1 || !v2) return;

    t = (node*)malloc(sizeof(node));
    t->next = v1->point;
    v1->point = t;
    t->point = v2;
}

// Function to print the graph
void printgraph() {
    node *t1, *t2, *t3;
    printf("\nVertex\tEdge List\n");
    t1 = g;
    while(t1 != NULL) {
        printf("\n%d\t", t1->data);
        t2 = t1->point;
        while(t2 != NULL) {
            t3 = t2->point;
            printf("%d ", t3->data);
            t2 = t2->next;
        }
        t1 = t1->next;
    }
}

// Function to insert into the topological sort order list at the beginning
void topsorting(int n) {
    topsort *z = (topsort*)malloc(sizeof(topsort)); 
    z->n = n;
    z->next = tsort;
    tsort = z;
}

// Function to print the topological sort order
void topsortout() {
    topsort *t = tsort;
    while(t != NULL) {
        printf("%d, ", t->n);
        t = t->next;
    }
}

// DFS visit function
void dfs_visit(node *u) {
    node *t, *t1;
    u->status = 1;  // mark vertex as visited
    printf("%d, ", u->data);
    ++time;
    d[u->data] = time;  // store discovery time

    t = u->point;
    while(t != NULL) {  
        t1 = t->point;
        if(t1->status == 0)  // if not visited
            dfs_visit(t1);
        t = t->next;
    }
    ++time;
    f[u->data] = time;  // store finish time
    topsorting(u->data);  // add the node to topological sort
}

// DFS search function
void dfs(node *g1) {
    node *t = g;
    while(t != NULL) {  
        t->status = 0;  // mark all vertices as not visited
        t = t->next;
    }
    dfs_visit(g1);
}

// Enqueue operation for BFS
void enque(node *s) {
    int r1 = (rear + 1) % SIZE;
    if (r1 == front) {
        printf("Queue is full \n");
        exit(1);
    }
    rear = r1;
    q[rear] = s;
}

// Check if queue is empty
int emptyq() {
    return front == rear;
}

// Dequeue operation for BFS
node* deque() {
    if (emptyq()) {
        printf("Queue is empty\n");
        exit(2);
    }
    front = (front + 1) % SIZE;
    return q[front];
}

// BFS function
void bfs(node *s) {
    node *t = g, *t1, *u;
    while(t != NULL) {
        t->status = 0;  // mark all vertices as not visited
        t = t->next;
    }
    
    s->status = 1;  // mark start vertex as visited
    printf("%d, ", s->data);
    enque(s);

    while(!emptyq()) {
        u = deque();
        t = u->point;
        while(t != NULL) {  
            t1 = t->point;
            if(t1->status == 0) {
                printf("%d, ", t1->data);
                t1->status = 1;
                enque(t1);  // enqueue the adjacent node
            }
            t = t->next;
        }
    }
}

// Main function  
int main() {
    // Add vertices
    addvertex(1);
    addvertex(2);
    addvertex(3);
    addvertex(4);
    addvertex(5);

    // Add edges
    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(2, 4);
    addedge(4, 3);
    addedge(4, 5);

    // Print graph
    printf("The graph is:\n");
    printgraph();

    // DFS traversal
    printf("\nDFS traversal: ");
    dfs(find(1));

    // BFS traversal
    printf("\nBFS traversal: ");
    bfs(find(1));

    // Topological sort output
    printf("\nTopological sort order: ");
    topsortout();

    return 0;
}

