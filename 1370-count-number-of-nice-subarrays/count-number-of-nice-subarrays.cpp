class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        freq[0] = 1;
        int odd_count = 0;
        int count = 0;
        for(int num : nums){
            if(num % 2 == 1){
                odd_count++;
            }
            if(freq.count(odd_count - k)){
                count += freq[odd_count - k];
            }
            freq[odd_count]++;
        }
        return count;
    }
};