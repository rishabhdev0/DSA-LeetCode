class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        // Count frequency of each number
        for(int num : nums){
            freq[num]++;
        }
        for(auto it = freq.begin(); it != freq.end(); it++){
            if(it->second == 1){
                return it->first;
            }
        }
        
        return -1; 
    }
};