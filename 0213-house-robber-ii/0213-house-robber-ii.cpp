class Solution {
public:
    int dp(vector<int> num){
        int prev = num[0];
        int prev2 = 0;
        for(int i=1;i<num.size();i++){
            int ntake, take;
            take = num[i];
            
            if(i>1){
                take += prev2;
            }
            ntake = prev;
            int curr = max(ntake, take);
            prev2 = prev;
            prev= curr;
        }
        return prev;
        
    }
    
    int rob(vector<int>& nums) {
        
        //edge case
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!= 0){
                temp1.push_back(nums[i]);
            }
            if(i!= nums.size()-1){
                temp2.push_back(nums[i]);
            }
        }
        
        return max(dp(temp1), dp(temp2));
    }
};