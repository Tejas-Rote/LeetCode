class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0;i<n;i++){
            int sIndex = i;
            bool found = false;
            int j;
            if(sIndex == n-1){
                j = 0;
            }else {
                j = sIndex+1;
            }
            while(j<n){
                if( j == sIndex){
                    ans[i] =-1;
                    // found = true;
                    break;
                }
                // cout<<nums[j]<<" ";
                if(nums[j] > nums[i]){
                    ans[i] = nums[j];
                    // found = true;
                    break;
                }
                
                if(j == n-1){
                    j = 0;
                }else {
                    j++;
                }
                
            }
                // cout<<endl;
        }
        
        return ans;
    }
};