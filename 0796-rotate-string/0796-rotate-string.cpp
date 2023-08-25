class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(n == 1){
            return s == goal;
        }
        for(int i=1;i<=n;i++){
            rotate(s.begin(), s.begin()+1, s.end());
            // cout<<s<<endl;
            if(s == goal){
                return true;
            }
        }
        return false;
    }
};