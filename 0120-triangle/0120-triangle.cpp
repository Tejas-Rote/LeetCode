class Solution {
public:
    int helper(int row, int col, vector<vector<int>> &dp,vector<vector<int>>& triangle){
        int n = dp.size();
        if(row == dp.size()-1){
            return triangle[row][col];
        }
        
        if(dp[row][col] != -1) return dp[row][col];
        
        int down = INT_MAX, diag = INT_MAX;
        if(row<n){
            down = triangle[row][col] + helper(row +1 , col , dp , triangle);
        }
        
        if(col < n){
            diag = triangle[row][col] + helper(row + 1, col + 1, dp , triangle);
        }
        
        
        return dp[row][col] = min(diag, down);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n , vector<int> (n, -1));
        return helper(0 , 0 , dp, triangle);
    }
};