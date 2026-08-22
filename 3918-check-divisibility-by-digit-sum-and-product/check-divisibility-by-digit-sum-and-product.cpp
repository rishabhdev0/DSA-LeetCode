class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;
        int prod = 1;
        int sum = 0;

        while(n > 0){
           int digit = n % 10;
           sum += digit;
           prod *= digit;
           n /= 10;
        }
        return num % (sum + prod) == 0;
    }
};