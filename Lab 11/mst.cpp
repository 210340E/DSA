#include<bits/stdc++.h>
using namespace std;
#define max 6

int minKey(int key[], bool MSTset[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < max; v++)
        if (MSTset[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[max][max])
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < max; i++)
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int graph[max][max])
{
    int parent[max]; 
    int key[max];   
    bool MSTset[max];  

    for (int i = 0; i < max; i++)
        key[i] = INT_MAX, MSTset[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < max-1; count++)
    {
        int u = minKey(key, MSTset);
        MSTset[u] = true;

        for (int v = 0; v < max; v++)
            if (graph[u][v] && MSTset[v] == false && graph[u][v] <  key[v])
                parent[v]  = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

int main()
{
    int graph[max][max] = {{0,3,0,0,0,1},
                       {3,0,2,1,10,0},
                       {0,2,0,3,0,5},
                       {0,1,3,0,5,0},
                       {0,10,0,5,0,4},
                       {1,0,5,0,4,0}
                      };

    primMST(graph);

    return 0;
}
