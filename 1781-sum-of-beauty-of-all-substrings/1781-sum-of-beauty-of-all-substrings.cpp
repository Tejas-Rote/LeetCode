class Solution {
public:

    int beautySum(string s) {
       int sum=0;
       for(int i=0;i<s.size();i++)
       {
            unordered_map<char,int>m;
            for(int j=i;j<s.length();j++)
            {
               m[s[j]]++;
               int maxi=0;
               int mini=INT_MAX;
               for(auto it:m)
               {
                     maxi=max(maxi,it.second);
                     mini=min(mini,it.second);
               }
               if(maxi-mini>0)
                  sum+=maxi-mini;
               }
       } 
       return sum;
    }
};