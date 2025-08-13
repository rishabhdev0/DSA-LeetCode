class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false; // zero and negative number
        if(n==1) return true; // base case
        if(n%3 != 0) return false; // not divisble by 3
        return isPowerOfThree(n/3);
    }
};