#include <stdio.h>
#include <stdbool.h>

#define V 6
#define INF 99999

int minDist(int dist[], bool spt[]) {
    int min = INF, idx = -1;
    for (int i = 0; i < V; i++)
        if (!spt[i] && dist[i] <= min)
            min = dist[i], idx = i;
    return idx;
}

void dijkstra(int g[V][V], int src) {
    int dist[V]; bool spt[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, spt);
        spt[u] = true;
        for (int v = 0; v < V; v++)
            if (!spt[v] && g[u][v] && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    printf("Vertex Distance from %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main() {
    int g[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    dijkstra(g, 0);
    return 0;
}
