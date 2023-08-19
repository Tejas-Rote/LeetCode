class Solution {
public:
    int strStr(string a, string b) {
        int index = a.find(b);
        if(index != string::npos) return index;
        else return -1;
    }
    
};