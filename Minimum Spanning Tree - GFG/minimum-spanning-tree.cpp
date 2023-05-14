//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        int graph[V][V] = {0};
        memset( graph, 0, sizeof(graph) );
        for (int i = 0; i<V; i++) {
            for (auto u:adj[i]) {
                graph[i][u[0]] = u[1];
                
            }
        }
        
        
        
        
        
        int key[V], res = 0;
        fill(key, key + V, INT_MAX);
        bool mSet[V];
        key[0] = 0;
        for (int i = 0; i < V; i++)
        {
            mSet[i] = false;
        }
    
        for (int count = 0; count < V; count++)
        {
            // for any start vertex here vecter 0 check for key and if it is visited
            // if key(edge wieght is smaller than the set then set the new key edge value)
            int u = -1;
            for (int i = 0; i < V; i++)
            {
                if (!mSet[i] && (u == -1 || key[i] < key[u]))
                {
                    u = i;
                }
            }
            mSet[u] = true;
            res += key[u];
    
            // always get the minimum values and update the key values after each vertex is added to the mSet
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] != 0 && mSet[v] == false)
                {
                    key[v] = min(key[v], graph[u][v]);
                }
            }
        }
    
        return res;
    
    
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends