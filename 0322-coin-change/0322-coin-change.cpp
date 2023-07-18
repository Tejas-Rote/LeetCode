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
        if(amount ==0){
            return 0;
        }else {
            //memo
            // vector<vector<int>> dp (n, vector<int> (amount+1 , -1) );
            // int res = helper(n-1 , amount, coins, dp);
            // return res == 1e9 ? -1 : res;
            
            // vector<vector<int>> dp (n, vector<int> (amount+1 ,0));
            vector<int> prev(amount+1, 0), cur(amount+1, 0);
            //base case 
            for(int i=0; i<=amount; i++){
                if(i%coins[0] == 0)  
                    prev[i] = i/coins[0];
                else prev[i] = 1e9;
            }
            
             for(int ind = 1; ind<n; ind++){
                for(int target = 0; target<=amount; target++){

                    int notTake = 0 +prev[target];
                    int take = 1e9;
                    if(coins[ind]<=target)
                        take = 1 + cur[target - coins[ind]];

                     cur[target] = min(notTake, take);
                }
                 prev = cur;
            }

            int ans = prev[amount];
            if(ans >=1e9) return -1;
            return ans;
            
        }
    }
};