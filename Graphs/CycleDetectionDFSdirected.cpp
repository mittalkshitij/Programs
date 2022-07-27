
// CYCLE DETECTION USING DFS DIRECTED GRAPH 

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
   // adj[v].push_back(u);  //  ---> for undirected graph
}

bool checkForCycle(int node, vector<int> adj[],int visited[],int dfsVis[])
{
    
    if(visited[node]==0)
    {
    visited[node]=1;
    dfsVis[node]=1;

    for(auto it: adj[node])
    {
        if(!visited[it])
        {
            if(checkForCycle(it,adj,visited,dfsVis))
            return true;
        }
        else if(dfsVis[it])
        return true;
    }
    }
    
    dfsVis[node]=0;
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    int visited[V],dfsVis[V];

    memset(visited , 0, sizeof visited);
    memset(dfsVis , 0, sizeof dfsVis);



    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(checkForCycle(i,adj,visited,dfsVis))
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
    for (int i=0;i<m;i++)
    {
        int u,v;  // u -> starting node of edge ;;  v-> ending node of edge // u-> v
        cin>>u>>v;
        addEdge(adj,u,v);
    }


    bool ans=isCycle(n,adj);

    cout<<ans;
    
   return 0;
}