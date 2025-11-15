#include <cmath> // for ceil function

class Solution {
private:
    bool canDivide(vector<int>& nums, int threshold, int divisor) {
        int total = 0;
        
        for(int num : nums) {
            
            total += ceil((double)num / divisor);
            
            if(total > threshold) {
                return false;
            }
        }
        
        return total <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int result = high;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(canDivide(nums, threshold, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};