
//  Graph Representation Using Adjancency list  (DIRECTED GRAPH)

#include<bits/stdc++.h>
using namespace std;
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

        adj[u].push_back(v);
        //adj[v].push_back(u);  //  ---> for undirected graph
    }



    // print adj list
    for (int j = 0; j < n; ++j) {
        cout << "\n Adjacency list of vertex " << j << "\n"<<j ;
        for (auto x : adj[j])
            cout << "-> " << x;
        cout<<endl;
    }

   return 0;
}