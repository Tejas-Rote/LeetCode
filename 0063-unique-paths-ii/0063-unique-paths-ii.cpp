class Solution {
public:
    int helper(vector<vector<int>> &a, int i , int j, vector<vector<int>> &dp){
        if(i>=0 && j>=0 && a[i][j] ==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = helper(a, i , j-1, dp);
        int left = helper(a  , i-1, j, dp);
        dp[i][j] = left + up;
        
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> dp (m, vector<int> (n,-1));
        
        return helper(obstacleGrid, m-1, n-1,  dp);
        
    }
};