class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &data){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = data.size();
        int m = data[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            
            int delrow[] = {-1, 0, +1, 0}; 
            int delcol[] = {0, -1, 0, +1}; 
            for(int i=0;i<4;i++){
                int nrow = row+ delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && ncol>=0 && ncol<m &&nrow<n && data[nrow][ncol] == '1' && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<char>> data = grid;
        int  n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,vis,data);
                }
            }
        }
        
        return cnt;
    }
};