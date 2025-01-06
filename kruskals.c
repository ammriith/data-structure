#include <stdio.h>
#include <stdlib.h>

int i, j, u, v, ru, rv, n, ne = 0;
int min, mincost = 0, cost[9][9], parent[9];

int find(int u) {
    // Find the root of the set
    while (parent[u])
        u = parent[u];
    return u;
}

void uni(int ru, int rv) {
    // Union of two sets
    parent[rv] = ru;
}

void main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) // If no edge, set to infinity (999)
                cost[i][j] = 999;
        }
    }

    printf("The edges of minimum cost spanning tree are:\n");

    while (ne < n - 1) {  // Kruskal's algorithm loop until we have n-1 edges
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                // Find the minimum edge that has not been included
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        ru = find(u);
        rv = find(v);

        if (ru != rv) {  // If the vertices belong to different sets, include this edge
            uni(ru, rv);
            printf("Edge (%d, %d) = %d\n", u, v, min);
            mincost += min;
            ne++;  // Increment the number of edges included in the MST
        }

        // Remove the chosen edge from further consideration
        cost[u][v] = cost[v][u] = 999;
    }

    printf("\nMinimum cost of the spanning tree = %d\n", mincost);
}

