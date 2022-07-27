
//DFS OF AN UNDRIECTED GRAPH


// BFS OF AN UNDIRECTED GRAPH

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

void dfs(int node,vector<int> &visited,vector<int> adj[],vector<int> &storedfs)
{
    storedfs.push_back(node);
    visited[node]=1;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            dfs(it,visited,adj,storedfs);
        }
    }
}

//DFS OF GRAPH
vector<int> dfsofGraph(int V, vector<int> adj[])
{
    vector<int> storedfs;
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,storedfs);
        }
    }
    return storedfs;
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

    vector<int> storedfs=dfsofGraph(n,adj);

    for (auto element : storedfs) {
        cout << element << " ";
    }
    

   return 0;
}