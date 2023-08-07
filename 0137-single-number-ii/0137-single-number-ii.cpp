class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        sort(nums.begin(), nums.end());

        if (nums[1] != nums[0]) {
            return nums[0];
        }

        if (nums[n - 1] != nums[n - 2]) {
            return nums[n - 1];
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                ans = nums[i];
                break;
            }
        }
        // unordered_map<int, int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // int ans = 0;
        // for(auto i: mp){
        //     if(i.second == 1){
        //         ans = i.first;
        //         break;
        //     }
        // }
        return ans;
    }
};