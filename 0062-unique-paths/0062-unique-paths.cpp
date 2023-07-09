class Solution {
public:
    
    
    int uniquePaths(int m, int n) {
    //TABULATION
        vector<vector<int>> dp (m, vector<int> (n,0));
        for(int row =0;row<m;row++){
            for(int col=0;col<n;col++){
                if(row == 0 && col ==0){
                    dp[row][col] = 1;
                        continue;
                }
                
                int up=0; 
                if(row>0){
                    up = dp[row-1][col];    
                }
                
                int left=0;
                if (col>0){
                   left =  dp[row][col-1];
                }
                
                dp[row][col] = left + up;
            }
        }
        return dp[m-1][n-1];


    }
};