class Solution {
public:
    void helper(vector<int>& nums, int index, set<vector<int>> &s) {
        if (index == nums.size()) {
            s.insert(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            helper(nums, index + 1,  s);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> vis (n, 0);
        set<vector<int>> s;
        helper(nums, 0, s);
        for(auto it : s){
            ans.push_back(it);
        }
        
        return ans;
    }
};