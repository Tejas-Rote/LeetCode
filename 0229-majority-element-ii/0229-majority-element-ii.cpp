class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n== 1){
            return {nums[0]};
        }
        if(n == 2 && nums[0] != nums[1]){
            return {nums[0], nums[1]};
        }
        sort(nums.begin(), nums.end());
        
        vector<int> ans;
        set<int> s;
        int prev;       
        int cnt =1;
        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1]== nums[i]){
                cnt++;
                if(cnt>n/3){
                    s.insert(nums[i]);
                    cout<<nums[i]<<" ";
                }
            }
            else {
                cnt =1;
            }    
        }
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};