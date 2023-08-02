class Solution {
public:
    void helper(int open , int close, int n , string s , vector<string> &ans){
        if(s.size()== (2*n)){
            ans.push_back(s);
            // s="";
            return ;
        }
        if(open<n){
            helper(open+1, close, n , s+"(", ans);
        }
        if(close<open){
            helper(open , close+1, n, s+")", ans);
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        helper(0,0 , n,s, ans);
        return ans;
        
    }
};