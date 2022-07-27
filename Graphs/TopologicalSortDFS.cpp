
// TOPOLOGICAL SORT.. FOR AN EDGE U-> V , U SHOULD APPEAR BEFORE V IN THE SORTING ORDER.. ONLY APPLIED FOR DAG Graph

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    // adj[v].push_back(u);  //  ---> for undirected graph
}

void findtoposort(int node, vector<int> adj[],vector<int> &visited,stack<int> &st)
{
    visited[node]=1;

    for(auto it:adj[node])
    {
        if(!visited[it])
        {
            findtoposort(it,adj,visited,st);
        }
    }

    st.push(node);

}

vector<int> toposort(int V, vector<int> adj[])
{
    vector<int> visited(V,0);

    stack<int> st;

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            findtoposort(i,adj,visited,st);
        }
    }

    vector<int> topo;

    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
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