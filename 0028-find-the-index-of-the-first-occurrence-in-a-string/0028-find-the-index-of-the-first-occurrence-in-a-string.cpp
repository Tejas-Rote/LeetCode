class Solution {
public:
    int strStr(string a, string b) {
        // int index = a.find(b);
        // if(index != string::npos) return index;
        // else return -1;
        
        
        int m = a.length();
        int n = b.length();

        if (m == 0 || n == 0 || m < n) return -1;  

        int i = 0, j = 0;
        while (i < m && j < n) {
            if (a[i] == b[j]) {  
                i++;
                j++;
                if (j == n) {  
                    return i - n;
                }
            } else {  
                i = i - j + 1;  
                j = 0;  
            }
        }
        return -1;          
    }
    
};