class Solution {
public:
    
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
//         if(n==m){
//             sort(s1.begin(), s1.end());
//             sort(s2.begin(), s2.end());
//             return s1 == s2;
//         }
//         set<string>s ;
//         do {
//             s.insert(s1);
//         } while(next_permutation(s1.begin(), s1.end()));
        
       
        int sIndex = 0;
        int eIndex = n ;
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= m - n; i++) {
            string subStr = s2.substr(i, n);
            sort(subStr.begin(),subStr.end());
            
            // cout << "Substring in window [" << i << ", " << i + n - 1 << "]: " << subStr << std::endl;
            if( s1 == subStr){
                return true;
            }
            // if(s.find(subStr) != s.end()){
            //     return true;
            // }
        }
        
        // cout<<endl;
        return false;
    }
}; 