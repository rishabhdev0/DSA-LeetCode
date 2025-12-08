class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        
        while (n != 0) {
            // Check if the least significant bit is 1
            if (n & 1) {
                count++;
            }
            // Right shift n 
            n = n >> 1;
        }
        
        return count;
    }
};