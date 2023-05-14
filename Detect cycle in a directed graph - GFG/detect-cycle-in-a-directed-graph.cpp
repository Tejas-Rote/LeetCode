//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   
    bool isCyclic(int V, vector<int> adj[]) {
       
        vector<int> indegree(V,0);
        
        for(int i=0;i<V;i++){
            for(int x : adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        int count =0 ;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(q.empty() == false){
            int u = q.front();
            q.pop();
            
            for(int v: adj[u]){
                    if(--indegree[v] == 0){
                        q.push(v);
                    }
            }
            count++;
        }
        
        if(count != V){
            return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends