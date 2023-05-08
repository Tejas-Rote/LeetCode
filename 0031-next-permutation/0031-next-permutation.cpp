class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        bool val = next_permutation(nums.begin(), nums.end());
        if(val == true){
             // next_permutation(nums.begin(), nums.end());
            for(int i=0; i<nums.size();i++){
                cout<<nums[i];
            }
        }else{
            sort(nums.begin(), nums.end());
            for(int i=0; i<nums.size();i++){
                cout<<nums[i];
            }
        }
        
    }
};