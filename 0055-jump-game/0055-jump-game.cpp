class Solution {
public:
    bool helper(int i, vector<int> &a, vector<int> &dp){
        if(i==a.size()-1) return true;
        if(dp[i]!=-1) return dp[i];
        int reachable=i+a[i];
        
        for(int k=i+1;k<=reachable;k++){
             if(helper(k,a,dp)){
                return dp[i]=true;
             } 
        }
        return dp[i]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1 , -1);
        return helper(0, nums, dp);
    }
};