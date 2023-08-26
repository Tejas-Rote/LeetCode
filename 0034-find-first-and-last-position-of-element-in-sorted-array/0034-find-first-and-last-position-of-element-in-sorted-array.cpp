class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first, last;
        int ind = lower_bound(nums.begin(), nums.end(), target)- nums.begin();
        if(ind == nums.size() || nums[ind] != target){
            return {-1 , -1};
        }
        first = ind;
        last  = upper_bound(nums.begin(), nums.end(), target)- nums.begin() -1;
        
        return {first, last};
    }
};