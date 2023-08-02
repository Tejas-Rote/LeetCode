class Solution {
public:
    int helper(int ind, int n, vector<int> &dp){
        if( ind == n){
            return 1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int one = helper(ind+1, n, dp);
        int two=0;
        if(ind+2 <=n){
            two = helper(ind+2, n, dp);
        }
        
        return dp[ind] = one + two;
        
    }
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // return helper(0, n, dp);
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};