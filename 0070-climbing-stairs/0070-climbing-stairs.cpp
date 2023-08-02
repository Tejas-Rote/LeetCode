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
        vector<int> dp(n+1, -1);
        return helper(0, n, dp);
    }
};