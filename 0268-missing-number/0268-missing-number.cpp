class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum +=nums[i];
        }
        
        int sum2 = (nums.size() * (nums.size()+1))/2;
        
        return sum2 - sum;
        }
};