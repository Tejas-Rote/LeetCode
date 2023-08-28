class Solution {
public:
    int findMin(vector<int>& nums) {       
        int n = nums.size();
        int l =0;
        int r = n-1;
        int mini = INT_MAX;
        while(l<=r){
            int mid = l + (r-l)/2;
            mini = min(mini, nums[mid]);
            if(nums[mid] >= nums[l]){
                mini = min(mini, nums[l]);
                l = mid+1;
            }else {
                mini = min(mini, nums[mid]);
                r = mid-1;
            }
        }
        return mini;
        
    }
};