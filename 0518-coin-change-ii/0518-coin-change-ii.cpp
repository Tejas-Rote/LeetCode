class Solution {
public:
    int helper(int i , int target , vector<int> & a , vector<vector<int>> & dp){
        if(i==0){
            return (target%a[0]==0);
        }
        if(dp[i][target] != -1) return dp[i][target];
        int ntake = helper(i-1 , target, a , dp);
        int take =0;
        if(a[i] <= target){
            take = helper(i, target-a[i], a, dp);
        }
        
        return dp[i][target] = take + ntake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n+1, vector<int> (amount+1 , -1));
        int res = helper(n-1, amount , coins,dp);
        res == 1e9 ? res =0: res;
        return res;
    }
    
};