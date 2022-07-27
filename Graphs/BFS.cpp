
// BFS OF AN UNDIRECTED GRAPH

#include<bits/stdc++.h>
using namespace std;


void addEdge(vector<int> adj[], int u, int v)
{

    adj[u].push_back(v);
    adj[v].push_back(u);  //  ---> for undirected graph
}

//BFS OF GRAPH
vector<int> bfsofGraph(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> visited(V+1,0);

    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);

            visited[i]=1;

            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node])
                {
                    if(!visited[it])
                    {
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        }
    }

    return bfs;
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

    vector<int> bfs=bfsofGraph(n,adj);

    for (auto element : bfs) {
        cout << element << " ";
    }
    

   return 0;
}