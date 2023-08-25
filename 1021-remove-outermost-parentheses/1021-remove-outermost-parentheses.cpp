class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open = 0, close = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                open++;
                if (open > 1) {
                    ans += '(';
                }
            } else if (s[i] == ')') {
                close++;
                if (open > close) {
                    ans += ')';
                }
                if (open == close) {
                    open = 0;
                    close = 0;
                }
            }
        }
        return ans;
    }
};