//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

//   void helper(int row, int col , vector<vector<char>> grid, vector<vector<bool>> visited){
//         int n = grid.size();
//         int m = grid[0].size();
//         visited[row][col] = true;
//         int delrow[]={0,0,1,-1,1,1,-1,-1,};
//         int delcol[]={1,-1,0,0,1,-1,-1,1};
//         for(int i = 0; i < 8; i++){
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
//             i f(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == false && grid[nrow][ncol] == '1'){
//                 helper(nrow, ncol, grid, visited);
//             }
//         }
//     }
    
        
        
        
//     int numIslands(vector<vector<char>>& grid) {
//         // Code here
//         int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<bool>> visited;
//         for(int i=0;i<n;i++){
//             vector<bool> temp;
//             for(int j=0;j<m;j++){
//                 temp.push_back(false);
//             }
//             visited.push_back(temp);
//         }
        
//         int count =0;
//         for(int i=0;i<n;i++){
//             for(int j =0;j<m;j++){
//                 if(visited[i][j] == false && grid[i][j] == '1'){
//                     count++;
//                     helper(i,j,grid, visited);
//                 }
//             }
//         }
        
//         return count;
//     }

    void dfs(int row, int col, int n, int m, vector<vector<int>>& vis, vector<vector<char>>&  grid){
        vis[row][col] = 1;
        int delrow[]={0,0,1,-1,1,1,-1,-1,};
        int delcol[]={1,-1,0,0,1,-1,-1,1};
        for(int i = 0; i < 8; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, n, m, vis, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, n, m, vis, grid);
                }
            }
        }
        return cnt;
    }


};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends