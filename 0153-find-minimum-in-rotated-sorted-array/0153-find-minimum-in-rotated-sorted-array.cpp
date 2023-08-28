class Solution {
public:
    int findMin(vector<int>& nums) {
//         int start;
//         int index =0;
//         int rotate;
//         int min=0;
//         for( int i=0;i<nums.size()-1;i++){
//             if(nums[i]>nums[i+1]){
//                 min=nums[i+1];
//                 index = i+1;
//                 break;
//             }
//         }
        
//         if(index == 0){
//             min = nums[0];
            
//         }
//         return min;
        
        int n = nums.size();
        int l =0;
        int r = n-1;
        int mini = INT_MAX;
     
        
        while(l<=r){
            int mid = l + (r-l)/2;
            // cout<<mid<<endl;
            mini = min(mini, nums[mid]);
            if(nums[mid] >= nums[l]){
                mini = min(mini, nums[l]);
                l = mid+1;
            }else {
                mini = min(mini, nums[mid]);
                r = mid-1;
            }
        }
        return mini;
        
    }
};