class Solution {
private: 
    void helper(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int index){
        
        
        if(index  == nums.size())
        {
            ans.push_back(temp);
            return;
        }        
        
        temp.push_back(nums[index]);
        helper(ans, temp , nums , index +1);
        temp.pop_back();
        
        helper(ans, temp , nums , index +1);
    
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        helper(ans, temp , nums, 0);
        
        
        // for(int i=0; i<n; i++)
        // {
        //     int sz = ans.size();
        //     for(int j=0; j<sz; j++)
        //     {
        //         vector<int> temp = ans[j];
        //         temp.push_back(nums[i]);
        //         ans.push_back(temp);
        //     }
        // }
        
        return ans;
    }
};

