class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0){ 
            int remainder = x % 10;
            // doing this to avoidd overflow as it will be over bound
            if(result > INT_MAX / 10 || result < INT_MIN / 10){
                return 0;
            }
            result = (result * 10) + remainder; 
            x /= 10;
        } 
        return result;
    }
};
