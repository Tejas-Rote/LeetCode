class Solution {
public:
    int candy(vector<int>& r) {
        int count =0;
        
        int n = r.size();
        vector<int> c(n, 1);
        if(n == 1){
            return 1;
        }
        
        for (int i = 1; i < n; i++)
            if (r[i] > r[i - 1]) c[i] = c[i - 1] + 1;
        
        for (int i = n - 2; i>=0; i--)
            if (r[i] > r[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
            
        
        for(int i=0;i<n;i++){
            count += c[i];
        }
        // cout<<endl;
        
        
        
        return count;
    }
};