class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
private:
    int atMostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        unordered_map<int, int> freq;
        int i = 0, count = 0;
        
        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;
            
            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i++;
            }
            
            count += (j - i + 1);
        }
        
        return count;
    }
};