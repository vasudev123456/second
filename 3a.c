#include <stdio.h>

#define INF 99999
#define V 4 // Number of vertices in the graph

// Function to print the solution matrix
void printSolution(int dist[][V]) {
    printf("The following matrix shows the shortest distances"
           " between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }
}

// Floyd Warshall algorithm
void floydWarshall(int graph[][V]) {
    int dist[V][V];

    // Initialize distance matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update distance matrix considering all intermediate vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the solution
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, INF, 3, INF},
        {2, 0, INF, INF},
        {INF, 7, 0, 1},
        {6, INF, INF, 0}
    };

    floydWarshall(graph);
    return 0;
}
