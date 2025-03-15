#include<iostream>
#include<algorithm>
using namespace std;

#define Max 100

struct edge
{
    int u, v, weight;
};

int parent[Max];

int find(int i)
{
    if(parent[i] == i)
    {
        return i;
    }
    return parent[i] = find(parent[i]);
}

void unionset(int u, int v)
{
    int rootu = find(u);
    int rootv = find(v);
    parent[rootu] = rootv;
}

bool compareedge(edge a, edge b)
{
    return a.weight < b.weight;
}

void kruskal(edge edges[], int n, int e)
{
    sort(edges, edges + e, compareedge);

    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    cout<<"Minimum Spanning Tree: ";

    int mstweight = 0;
    int edgecount = 0;
    for(int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if(find(u) != find(v))
        {
            cout<<u<<" - "<<v<<" : "<<weight<<endl;
            unionset(u,v);
            mstweight += weight;
            edgecount++;

            if(edgecount == n - 1)
            {
                break;
            }
        }
    }

    cout<<"Total Minimum Cost: "<<mstweight<<endl;
}

int main()
{
    int n,e;
    cout<<"enter number of vertices and edges: "<<endl;
    cin>>n;
    cin>>e;

    edge edges[Max];

    cout<<"enter edges (u,v, weight): "<<endl;
    for(int i = 0; i < e; i++)
    {
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;
    }

    kruskal(edges, n, e);

    return 0;
}
