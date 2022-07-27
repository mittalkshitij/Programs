
// GRAPH COLORING PROBLEM -- NO ADJACNENT NODES SHOULD BE OF SAME COLOR

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

bool bipartiteBFS(int src,vector<int> adj[], int color[])
{

    queue<int> q;
    q.push(src);

    color[src]=1;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            return false;
        }
    }

    return true;
}


bool checkBipartite(vector<int> adj[],int V)
{

 int color[V];

 memset(color,-1,sizeof color);

 for(int i=0;i<V;i++)
 {
    if(color[i]==-1)
    {
        if(!bipartiteBFS(i,adj,color))
        return false;
    }
 }
 return true;
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

    if(checkBipartite(adj,n))
    cout<<"Yes it is bipartite";
    else 
    cout<<"No it isn't bipartite";
   return 0;
}
