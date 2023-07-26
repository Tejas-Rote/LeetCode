// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        // cout<<isBadVersion(4);
        
        int l = 1, h = n, mid;

        while(l<h){
            mid = l + (h-l)/2;
            if(isBadVersion(mid)){
                h = mid;
            }else {
                l = mid+1;
            }
        }  
        
        return l;

    }
};