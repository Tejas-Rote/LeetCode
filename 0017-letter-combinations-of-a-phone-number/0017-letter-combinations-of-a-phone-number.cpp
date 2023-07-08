class Solution {
private:    
    void helper(string digits,string temp,vector<string> &res)
    {
        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", 
                          "tuv", "wxyz"};
        
        if(digits.size()==0) 
        {
            res.push_back(temp);
            return;
        }
        
        
        string s = v[digits[0] - '0'];   
        digits.erase(digits.begin()+0); // remove that digit after considering it.
        
        for(int i=0;i<s.length();i++)
        { 
            helper(digits,temp+s[i],res);
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {

    if(digits== ""){
        return {};
    }
    vector<string> res;
        string temp = "";
        
    // helper(digits,res, temp );
    helper(digits, temp , res);

        
    return res;

    }
};