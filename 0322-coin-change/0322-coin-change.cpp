class Solution {
public:
    int helper(int i , int target , vector<int> &a , vector<vector<int>> &dp){
        if(i==0){
            if(target%a[i] == 0){
                return target/a[i];
            }
            else {
                // return -1;
                return 1e9;
            }
        }
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        
        int ntake = helper(i-1, target, a, dp);
        int take= INT_MAX;
        if(a[i]<=target){
            take = 1+ helper(i, target - a[i] , a ,dp);
        }
        return dp[i][target] = min(take , ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        //memo
        // cout<<"amt "<<amount<<endl;
        if(amount ==0){
            return 0;
        }else {
            
        vector<vector<int>> dp (n, vector<int> (amount+1 , -1) );
        int res = helper(n-1 , amount, coins, dp);
        return res == 1e9 ? -1 : res;
        }
    }
};