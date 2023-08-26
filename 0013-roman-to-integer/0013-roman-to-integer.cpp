class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanToInteger = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int ans = 0, prev = 0;
        for (int i = 0, n = s.size(); i < n; ++i) {
            char sym = s[i];
            int val = romanToInteger[sym];
            
            if (prev < val) {
                val -= 2 * prev;
            }
            
            ans += val;
            prev = val;
        }
        
        return ans;
    }
};