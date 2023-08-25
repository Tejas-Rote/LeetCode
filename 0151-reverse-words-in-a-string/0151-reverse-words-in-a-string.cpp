class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string t = "";
        int n = s.size();
        
        // Parse the words
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!t.empty()) {
                    v.push_back(t);
                    t = "";
                }
            } else {
                t += s[i];
            }
        }
        
        // Add the last word if present
        if (!t.empty()) {
            v.push_back(t);
        }
        
        // Reverse the vector of words
        reverse(v.begin(), v.end());
        
        // Construct the reversed string
        string ans;
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
            if (i != v.size() - 1) {
                ans += " ";
            }
        }
        
        return ans;
    }
};