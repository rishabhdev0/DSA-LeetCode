#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int curr_sum = 0;
        int i = 0;
        int j = 0;
        int max_sum = 0;
        
        while (j < n) {
            curr_sum += nums[j];
            freq[nums[j]]++;
            
            while (freq[nums[j]] > 1) {
                curr_sum -= nums[i];
                freq[nums[i]]--;
                i++;
            }
            
            max_sum = max(max_sum, curr_sum);
            j++;
        }
        
        return max_sum;
    }
};