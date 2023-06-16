class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>adj[n];
        for(int i =0;i<prerequisites.size();i++){
            // adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // for (int i = 0; i <n; i++)
        // {
        //     cout<<i<<" ->";
        //     for (int x : adj[i])
        //     {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        
        
        vector<int> ans;
        vector<int> indeg(n, 0);
        
        for(int i=0;i<n;i++){
            for(auto x:adj[i]){
                indeg[x]++;
            }
        }
        
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            ans.push_back(u);
            for(auto v : adj[u]){
                indeg[v]--;
                if(indeg[v] ==0){
                    q.push(v);
                }
            }
        }
        
        // imp if at the end a cycle is detected the number of nodes in sort result will not be equal to number of nodes. 
        if (ans.size() == n) return ans;
		return {};
        
        
        // return ans;
        
    }
};