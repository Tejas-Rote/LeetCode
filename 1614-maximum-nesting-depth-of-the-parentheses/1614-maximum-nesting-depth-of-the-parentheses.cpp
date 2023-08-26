class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int n = s.size();
        if(s.empty()){
            return 0;
        }
        int i=0;
        int open =0;
        while(i<n){
            if(s[i] == '('){
                open++;
            }
            
            if(s[i] == ')'){
                open--;
            }
            
            ans = max(ans, open);
            i++;
        }
        return ans;
    }
};