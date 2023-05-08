class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // vector<int> v;

        // for(auto i:mp){
        //     if(i.second == 2){
        //         v.push_back(i.first);
        //     }
        // }
        
        // return v;

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;


    }
};