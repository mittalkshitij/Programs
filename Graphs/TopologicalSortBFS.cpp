
// TOPOLOGICAL SORT.. FOR AN EDGE U-> V , U SHOULD APPEAR BEFORE V IN THE SORTING ORDER.. ONLY APPLIED FOR DAG Graph
// KAHN's ALGORITHM

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    // adj[v].push_back(u);  //  ---> for undirected graph
}


vector<int> toposort(int V, vector<int> adj[])
{
    
    queue<int> q;
    vector<int> indegree(V,0);

    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }

    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }

    vector<int> topo;

    while(!q.empty())
    {
        int node=q.front();
        q.pop();

        topo.push_back(node);

        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }


    return topo;
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

    vector<int> ans=toposort(n,adj);

    for (auto element : ans) {
        cout << element << " ";
    }


   return 0;
}