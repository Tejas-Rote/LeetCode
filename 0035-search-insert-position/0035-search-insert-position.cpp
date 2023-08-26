class Solution {
public:
    int searchInsert(vector<int>& a, int x) {
        int l = 0;
        int r = a.size()-1;
        int mid;
        while(l<=r){
             mid = l + (r-l)/2;
            
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
};