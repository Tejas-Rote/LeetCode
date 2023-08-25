class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char, char> s1, s2;
        for(int i = 0; i < s.size(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (s1.count(c1) && s1[c1] != c2) {
                return false;
            }

            if (s2.count(c2) && s2[c2] != c1) {
                return false;
            }

            s1[c1] = c2;
            s2[c2] = c1;
        }
        
        return true;
    }
};