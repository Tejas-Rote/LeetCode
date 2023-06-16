class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //inital idea
        
        // for (int i = 0; i <n; i++)
        // {
        //     cout<<i<<" ->";
        //     for (int x : adj[i])
        //     {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout<<endl;
                // for(int i=0;i<n;i++){
        //     if(outdeg[i] == 0){
        //         ans.push_back(i);
        //     }
        // }
        // vector<int> outdeg(n,0);
        
        int  n = graph.size();
        vector<int> adj[n];
        vector<int> indeg(n,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(auto x:graph[i]){
                // adj[i].push_back(x);
                // reversing the graph to deal with indegree instead of outdegree. 
                adj[x].push_back(i);
                indeg[i]++;

            }
        }
        

        
//         for(int i=0;i<n;i++){
            
//             for(auto x:adj[i]){
//                 // outdeg[i]++;
//                 indeg[x]++;
//             }
//         }
        
      
        
        queue<int> q;
                
        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            // cout<<u<<" ";
            ans.push_back(u);
            for(auto v:adj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        
        
        
        return ans;
    }
};