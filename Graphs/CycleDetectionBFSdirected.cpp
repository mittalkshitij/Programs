
// WE WILL FIND OUT THE TOPOLOGICAL SORT OF THE GRAPH. AS TOPOLOGICAL SORT CAN ONLY BE GENERATED FOR DAG GRAPH
// SO IF THE NO OF NODES IN THE TOPOLOGICAL SORT IS EQUAL TO THE TOTAL NO OF NODES
// SO THERE WILL BE NO CYCLE IN THE GRAPH

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    // adj[v].push_back(u);  //  ---> for undirected graph
}


bool toposort(int V, vector<int> adj[])
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

    int cnt=0;


    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cnt++;
   
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }

    if(cnt==V)
    return false;
    else
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

    bool ans=toposort(n,adj);

    cout<<ans;


   return 0;
}