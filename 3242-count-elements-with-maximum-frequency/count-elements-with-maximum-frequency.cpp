class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int max_freq = 0;
        int result = 0;
        unordered_map<int, int> freq;
        
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            max_freq = max(max_freq, freq[nums[i]]);
        }
        
        // Iterate through freq map 
        for(auto it = freq.begin(); it != freq.end(); it++) {
            if(it->second == max_freq) {  //  it->second 
                result += it->second;     // Add the frequency value
            }
        }
        
        return result;
    }
};