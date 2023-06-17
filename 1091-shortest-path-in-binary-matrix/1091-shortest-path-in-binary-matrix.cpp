class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        
        dist[0][0] = 0;
        vis[0][0]= 0;
        q.push({{0,0}, 0});
        
        int d;
    
        if(grid[0][0] !=0 || grid[n-1][n-1] !=0){
            return -1;
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            for(int i= -1;i<=1;i++){
                for(int j= -1;j<=1;j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow<n && ncol<n && nrow>=0 && ncol>=0 &&    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                        dist[nrow][ncol] = dist[row][col] + 1;                        
                        vis[nrow][ncol] = 1;
                        q.push({{nrow, ncol}, dis+1});
                        if(nrow == n-1 && ncol == n-1){
                            return dist[n-1][n-1];
                        }
                    }
                }
                
            }
            
        }
        
        // return dist[n-1][n-1];
        return -1;
        
    }
};