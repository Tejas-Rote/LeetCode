class Solution {
public:
    bool isPalindrome(string s, int i , int j){
        int n = s.size();
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else {
                return false;
            }
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t){
            return true;
        }
        int n = s.size();
        int i=0, j=n-1;
        while(i<j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else {
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
        
    }
};