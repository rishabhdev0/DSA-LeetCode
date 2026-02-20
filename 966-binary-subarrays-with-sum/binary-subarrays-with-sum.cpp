class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int , int>freq;
        freq[0] = 1; // as 0 is always present
        int sum = 0;
        int count = 0;
        for(int num  : nums){
            sum+=num;
            if(freq.count(sum - goal)){
                count+=freq[sum - goal];
            }
            freq[sum]++;
        }
        return count;
    }
};