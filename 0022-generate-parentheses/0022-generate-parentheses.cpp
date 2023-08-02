class Solution {
public:
    vector<string> ans;
    void helper(int open , int close, int n , string s){
        if(s.size()== (2*n)){
            ans.push_back(s);
            // s="";
            return ;
        }
        if(open<n){
            helper(open+1, close, n , s+"(");
        }
        if(close<open){
            helper(open , close+1, n, s+")");
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        string s;
        helper(0,0, n,s);
        return ans;
        
    }
};