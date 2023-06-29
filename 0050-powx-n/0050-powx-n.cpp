class Solution {
public:
    double myPow(double x, int n) {
        // double ans = 1;
        // if(n>0){
        //     ans = ans*x;
        //     myPow(ans, n-1);
        // }
        // if(n<0){
        //     ans = ans/x;
        //     myPow(ans, n+1);
        // }
        // if(n==0){
        //     return ans;
        // }
        // return ans;
        if(n < 0) {
            x = 1 / x;
        } 
        
        long num = labs(n);
        
        double pow = 1;
        
        while(num){ // equivalent to while(num != 0)
            if(num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }
            
            x *= x;
            num >>= 1;
        }
        
        return pow;
    }
};