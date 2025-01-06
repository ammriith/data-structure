#include<stdio.h>
#include<stdlib.h>

void main() {
    int u, v, n, i, j, ne = 1;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0) {
                cost[i][j] = 999;  // No edge
            }
        }
    }

    visited[0] = 1;  // Start from node 0
    printf("\n");

    // Main loop for Prim's Algorithm
    while(ne < n) {
        min = 999;  // Initialize minimum to a large number
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                // Check if this edge is valid and has minimum weight
                if(cost[i][j] < min) {
                    if(visited[i] != 0 && visited[j] == 0) { 
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Output the selected edge and its cost
        printf("\nEdge %d: (%d %d) Cost: %d", ne++, u + 1, v + 1, min); 
        mincost += min;  // Add the cost to the total MST cost
        visited[v] = 1;  // Mark the node as visited
        cost[u][v] = cost[v][u] = 999;  // Remove the selected edge
    }

    // Output the total minimum cost of the MST
    printf("\nMinimum cost = %d", mincost);
}

