class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;  // Use long long to handle potential overflow
        int n = s.size();
        int i = 0;
        bool neg = false;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign if present
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            neg = (s[i] == '-');
            i++;
        }

        // Start reading numbers
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            // Check for overflow
            if (ans > (INT_MAX - digit) / 10) {
                return neg ? INT_MIN : INT_MAX;
            }
            
            ans = ans * 10 + digit;
            i++;
        }

        if (neg) {
            ans = -ans;
        }

        // Check for overflow or underflow one more time
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};