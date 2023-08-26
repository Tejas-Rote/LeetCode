class Solution {
public:
    int helper(vector<int> & a, int x){
        int l = 0;
        int r = a.size()-1;
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(a[mid] == x){
                return mid;
            }
            
            if(a[mid] < x){
                 l = mid +1;
            }else {
                r = mid-1;
            }
        }
        
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        return helper(nums, target);
    }
};