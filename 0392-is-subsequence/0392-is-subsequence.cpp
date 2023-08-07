class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        if(s == ""){
            return true;
        }
        if(t == ""){
            return false;
        }
        if(s.size()< t.size()){
            swap(s,t);
        }
        while(i<s.size() && j<t.size()){
            // cout<<i<<" "<<j<<endl;
            // cout<<s[i]<<" "<<t[j]<<endl;
            if(s[i] == t[j]){
                i++;
                j++;
            }else {
                i++;
            }
        }
        // cout<<j<<" - "<<t.size()-1<<endl;
        return j == t.size();
    }
};