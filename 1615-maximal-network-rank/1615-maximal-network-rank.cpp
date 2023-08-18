class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int> (n, 0));
        vector<int> degree(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]][roads[i][1]] = 1;
            adj[roads[i][1]][roads[i][0]] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j] == 1){
                    degree[i]++;
                }
            }
        }
        
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j){
                    int val = degree[i] + degree[j];
                    if(adj[i][j] == 1){
                        val -=1;
                    }
                    maxi = max(maxi, val);
                }
            }
        }
        
        return maxi;
    }
};