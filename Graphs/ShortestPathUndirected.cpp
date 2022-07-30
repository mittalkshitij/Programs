
// SHORTEST PATH IN AN UNDRIECTED GRAPH WITH UNIT WEIGHTS

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

void shortestPath(vector<int> adj[],int n,int src)
{
    queue<int> q;
    int dist[n];

    for(int i=0;i<n;i++)
    {
        dist[i]=INT_MAX;
    }

    dist[src]=0;
    q.push(src);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it:adj[node])
        {
            if(dist[node]+1 < dist[it])
            {
                dist[it]=dist[node]+1;
                q.push(it);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<dist[i]<<" ";
    }


}

int main()
{

    int n,m;  // n-> no of nodes ;  m-> no of edges
    cin>>n>>m;

    vector<int> adj[n+1];

    //add edge func
    for (int i=0;i<m;i++)
    {
        int u,v;  // u -> starting node of edge ;;  v-> ending node of edge // u-> v
        cin>>u>>v;
        addEdge(adj,u,v);
        
    }

    shortestPath(adj,n,0);

   return 0;
}
