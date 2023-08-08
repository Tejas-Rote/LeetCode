class Solution {
public:
    bool helper(string &s1, string &s2, string &s3, int i , int j, int k, vector<vector<int>> &dp){
        if(i < 0 && j< 0 && k<0){
            return true;
        }    
        if(i>=0 && j>=0 && dp[i][j] != -1) return dp[i][j];
        
        if(i>=0 && j>=0 && s1[i] == s3[k] && s2[j] == s3[k]){
            return dp[i][j] = (helper(s1,s2,s3,i-1,j,k-1,dp) || helper(s1,s2,s3,i,j-1,k-1,dp));
        }
        else if(i>=0 &&  s1[i] == s3[k]){
            return helper(s1,s2,s3,i-1,j,k-1,dp); // imp not stored in dp table as will go out of bounds when completed
        }else if( j>=0 && s2[j] == s3[k]){
             return helper(s1,s2,s3,i,j-1,k-1,dp);// imp not stored in dp table as will go out of bounds when completed
        }
        else {
            return false;
        }
    }
    
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        int i=s1.size()-1,j=s2.size()-1,k=s3.size()-1;
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        return helper(s1,s2,s3, i,j,k,dp);
    }
};