class Solution {
public:
    set<int>s;
    bool helper(int n){
        if(n == 1){
            return true;
        }
        if(s.find(n) != s.end()){
            return false;
        }else {
            s.insert(n);
        }
        int sum =0;
        if(n>9){
            while(n>0){
                int digit = n%10;
                sum += digit*digit;
                n = n/10;
            }
        }else {
            sum = n*n;
        }
        
        // s.insert(sum);
        return helper(sum);
    }
    bool isHappy(int n) {
       return helper(n);
    }
};