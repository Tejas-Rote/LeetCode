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
        // return helper(0 , 0 , dp, triangle);
        
        // tabulation 
        // base case
        // not  i= n-1 as we calculated for that as a base case row
        for(int j=0;j<n;j++){
                dp[n-1][j] = triangle[n-1][j];
            }
    
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){

                int down = triangle[i][j]+dp[i+1][j];
                int diagonal = triangle[i][j]+dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
        
        
    }
};