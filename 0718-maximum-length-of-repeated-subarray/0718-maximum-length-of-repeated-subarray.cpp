class Solution {
public:
    
    int lcs(vector<int>& s1, vector<int>& s2){
        int n = s1.size();
        int m = s2.size();
        vector<int> prev (n+1, 0), cur(m+1, 0);
        int ans = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    int val = 1 + prev[j-1];
                    cur[j] = val;
                    ans = max(ans,val);
                }
                else
                    cur[j] = 0;
            }
            prev = cur;
        }

        return ans;

    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // cout<<s<<" "<<t<<endl;
        cout<<lcs(nums1, nums2);
        return lcs(nums1, nums2);
    }
};