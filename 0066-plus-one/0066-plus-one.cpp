class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n-1] < 9){
            digits[n-1] += 1;
            return digits;
        }
        else {
            
            if(n == 1){
                if(digits[0] == 9){
                    digits[0] = 1;
                    digits.push_back(0);
                    return digits;
                }
            }
            int carry = 0;            
            for(int i=n-1;i>=0;i--){
                if(i == 0 && carry == 1){
                    if(digits[0] != 9){
                         digits[i] += carry;
                    }else {
                        digits[i] =1;
                        digits.push_back(0);
                    }
                }else {
                        if(digits[i] == 9){
                            digits[i] = 0;
                            carry = 1;
                        }else{
                            digits[i] += carry;
                            break;
                        }
                }
            }
        }

        
        return digits;
    }
};