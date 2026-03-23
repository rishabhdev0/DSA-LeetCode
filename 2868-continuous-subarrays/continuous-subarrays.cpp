class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;
        int i = 0, j = 0;

        long long count = 0;

        while(j < n){
            freq[nums[j]]++;
            while(freq.rbegin()->first - freq.begin()->first > 2){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};