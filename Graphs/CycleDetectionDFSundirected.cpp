
// CYCLE DETECTION USING DFS FOR UNDRICETED GRAPH

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

bool checkForCycle(int node,int parent,vector<int> &visited,vector<int> adj[])
{
    visited[node]=1;

    for(auto it: adj[node])
    {
        if(visited[it]==0)
        {
            if(checkForCycle(it,node,visited,adj))
            return true;
        }
        else if(it!=parent)
        return true;
    }

    return false;

}

bool isCycle(int V, vector<int> adj[])
{
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++)
    {

        if(!visited[i])
        {
            if(checkForCycle(i,-1,visited,adj))
            return true;
        }
    }
    return false;

}
int main()
{

    int n,m;  // n-> no of nodes ;  m-> no of edges
    cin>>n>>m;

    vector<int> adj[n+1];

    //add edge func
    for (int i=1;i<=m;i++)
    {
        int u,v;  // u -> starting node of edge ;;  v-> ending node of edge // u-> v
        cin>>u>>v;
        addEdge(adj,u,v);
    }

    bool ans=isCycle(n,adj);

    cout<<ans;
    
   return 0;
}