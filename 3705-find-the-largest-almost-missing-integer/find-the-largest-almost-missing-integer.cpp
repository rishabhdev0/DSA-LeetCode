class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

       
        if (k == 1) {
            int ans = -1;

            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }

            return ans;
        }

         if(k==n){
            return *max_element(nums.begin() , nums.end());
         }
        
        int first = nums[0];
        int last = nums[n - 1];

        bool firstValid = (freq[first] == 1);
        bool lastValid = (freq[last] == 1);

        if (firstValid && lastValid) {
            return max(first, last);
        }

        if (firstValid) {
            return first;
        }

        if (lastValid) {
            return last;
        }

        return -1;
    }
};