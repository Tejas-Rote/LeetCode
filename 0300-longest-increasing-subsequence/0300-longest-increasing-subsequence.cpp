class Solution {
public:
    int helper(int idx, int prevIdx, vector<int> &a, vector<vector<int>> &dp){
        if(idx == a.size()){
            return  0;
        }
        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];
        
        int ntake = 0 + helper(idx+1, prevIdx, a, dp);
        int take = INT_MIN;
        if(prevIdx == -1 || a[idx]> a[prevIdx]){
            take = 1+ helper(idx+1, idx, a, dp);
        }
        
        return dp[idx][prevIdx+1] = max(ntake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(0, -1, nums, dp);
    }
};