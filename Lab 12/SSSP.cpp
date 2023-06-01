#include <iostream>
#include <climits>

using namespace std;

#define max 6 // define size of graph here

// find index of the node with minimum distance that hasn't been processed
int min_dis(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < max; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// implementation of Dijkstra's algorithm to find shortest path from source node to all other nodes
void dijkstra(int G[max][max], int src) {
    int dist[max];// array to store distances from source node to each node in graph
    bool sptSet[max];// array to keep track of which nodes have been processed
    for (int i = 0; i < max; i++)
        dist[i] = INT_MAX, sptSet[i] = false;// initialize all distances to infinity and sptSet to false
    dist[src] = 0;
    for (int count = 0; count < max - 1; count++) {
        int u = min_dis(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < max; v++)
            if (!sptSet[v] && G[u][v] && dist[u] != INT_MAX
                && dist[u] + G[u][v] < dist[v])
                dist[v] = dist[u] + G[u][v];
    }

    for (int i = 0; i < max; i++)// print out shortest distance from source node to all other nodes
        cout << "Shortest distance from city " << src << " to city " << i << ": " << dist[i] << endl;
}

// main function initializes graph and calls Dijkstra's algorithm
int main() {
    int G[max][max] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};
    int src;
    cout << "Enter the source city: ";
    cin >> src;
    dijkstra(G, src);
    return 0;
}
