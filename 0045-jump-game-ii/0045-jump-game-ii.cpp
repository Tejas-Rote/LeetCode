class Solution {
public:

    int minJumpsRecursive(vector<int>& nums, int i, vector<int>& dp) {
        if (i == nums.size() - 1) {
            return 0;
        }

      
        if (dp[i] != -1) {
            return dp[i];
        }

        int totalJumps = INT_MAX;
        int maxJumpLength = nums[i];

        for (int j = 1; j <= maxJumpLength && i + j < nums.size(); ++j) {
            int jumps = minJumpsRecursive(nums, i + j, dp);
            if (jumps != INT_MAX) {
                totalJumps = min(totalJumps, 1 + jumps);
            }
        }

        dp[i] = totalJumps;
        return dp[i];
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return minJumpsRecursive(nums, 0, dp);        
    }
};