class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();    //size of the array
        
        if(n < 3)     
            return false;

        int left = INT_MAX;
        int mid = INT_MAX;
        

        for(int i = 0; i < n ; i ++)
        {
            //if nums[i] is greater than mid means nums[i] is also greater than left means two elements before index i is less than nums[i] and that are left and mid. we find that it sataisfy the condition of triplet so we return true.
            if(nums[i] > mid)
                return true;
            
            // we find b in a < b < c because it is quite possible that c can be INT_MAX.
            else if(nums[i] > left && nums[i] < mid)
                mid = nums[i];
            
            //we find a smaller element than it's previous value.
            else if(nums[i] < left)
                left = nums[i];
        }
        
        return false;
    }
};