
// CYCLE DETECTION using BFS ON UNDIRECTD GRAPH

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

bool checkForCycle(int s,vector<int> &visited,vector<int> adj[])
{
    queue<pair<int,int>> q;

    visited[s]=1;
    q.push({s,-1});

    while(!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto it: adj[node])
        {
            if(!visited[it])
            {
                visited[it]=1;   
                q.push({it,node});
            }
            else if(parent!=it)
            return true;
        }
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
        if(checkForCycle(i,visited,adj))
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