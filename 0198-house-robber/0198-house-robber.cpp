class Solution {
public:
    int helper(int ind, vector<int>& arr, vector<int>& dp) {

        if (ind == 0)
            return arr[ind];
        
        if (ind < 0)
            return 0; // Base case: return 0 if the index is negative.

        if (dp[ind] != -1)
            return dp[ind];
        
        
        int nonPick = 0 + helper(ind - 1, arr, dp);
        int pick = arr[ind] + helper(ind - 2, arr, dp);

        return dp[ind] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> dp(n, -1);
        return helper(n - 1, nums, dp);
    }
};
