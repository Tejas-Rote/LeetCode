class Solution {
public:
    bool helper(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
        if(target==0)
            return true;

        if(ind == 0)
            return arr[0] == target;

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        bool notTaken = helper(ind-1,target,arr,dp);

        bool taken = false;
        if(arr[ind]<=target)
            taken = helper(ind-1,target-arr[ind],arr,dp);

        return dp[ind][target]= notTaken||taken;
    }
    bool canPartition(vector<int>& arr) {
        int totSum=0;
        int n = arr.size();
    
        for(int i=0; i<n;i++){
            totSum+= arr[i];
        }

        if (totSum%2==1) return false;

        else{
            int k = totSum/2;
            vector<vector<int>> dp(n,vector<int>(k+1,-1));
            return helper(n-1,k,arr,dp);
        } 
        
    }
};