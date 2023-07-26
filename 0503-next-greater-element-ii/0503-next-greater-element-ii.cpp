class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //optimal 
        stack<int> s; 
        int n = nums.size();
        vector<int> res(n, -1);
      
        for(int i = 0; i < n * 2; i++) {
            int idx = i >= n ? i - n : i;
            while(!s.empty() && nums[idx] > nums[s.top()]) {
                res[s.top()] = nums[idx];
                s.pop();
            }            
            if(res[idx] == -1) { 
                s.push(idx);
            } 
        }
        
        return res; 
        // initial approach
            
//         int n = nums.size();
//         vector<int> ans(n, -1);
//         int j, sIndex;
//         for(int i=0;i<n;i++){
//              sIndex = i;
//             if(sIndex == n-1){
//                 j = 0;
//             }else {
//                 j = sIndex+1;
//             }
//             while(j<n){
//                 if( j == sIndex){
//                     ans[i] =-1;
//                     // found = true;
//                     break;
//                 }
//                 // cout<<nums[j]<<" ";
//                 if(nums[j] > nums[i]){
//                     ans[i] = nums[j];
//                     // found = true;
//                     break;
//                 }
                
//                 if(j == n-1){
//                     j = 0;
//                 }else {
//                     j++;
//                 }
                
//             }
//                 // cout<<endl;
//         }
        
//         return ans;
    }
};