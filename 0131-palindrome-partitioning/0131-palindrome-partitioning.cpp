class Solution {
private: 
//     bool isPal(vector<string> ds){
//         string s = "";
//         for(int i=0;i<ds.size();i++){
//             s+=ds[i];
//         }
        
//         reverse(s.begin(), s.end());
//         string rs = s;
//         if(s != rs || s.size() == 1){
//             return false;
//         }
//         return true;
//     }
    
    
   bool isPalindrome(string s, int start, int end) {
     while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
    
    void helper(int index, string s, vector < string > & path,
    vector < vector < string > > & res){
        if (index == s.size()) {
          res.push_back(path);
          return;
        }
        for (int i = index; i < s.size(); ++i) {
          if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            helper(i + 1, s, path, res);
            path.pop_back();
          }
        }
    }
        
        
        
        // if(!isPal(ds)){
        //     // string a = (string)s[index];
        //     ds.push_back(string(1,s[index]));
        //     helper(ans, s, index+1, ds);
        //     ds.pop_back();
        // }
        // helper(ans, s, index+1, ds);
        // helper(ans, s, index+1, ds.push_back(string (1,s[index])));
    // }
    
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        helper(0, s, path, res);
        return res;
        
    }
};