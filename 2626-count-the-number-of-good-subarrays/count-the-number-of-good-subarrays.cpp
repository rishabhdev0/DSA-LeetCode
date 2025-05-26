class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map< int , int> freq;
        long long count = 0;
        long long pairs = 0;
        int i = 0;
        int j = 0;
        while(j<n){
           pairs+=freq[nums[j]]; // isse pahle humne kitne bar pair dekh liya hai 
           freq[nums[j]]++;
           while(pairs>=k){
            count +=(n-j);
            freq[nums[i]]--;
            pairs -=freq[nums[i]];
            i++;
           }
           j++;
        }
        return count;
    }
};