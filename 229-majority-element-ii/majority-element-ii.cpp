class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int size = n / 3;

        unordered_map<int,int> freq;

        for(int num : nums) {
            freq[num]++;
        }

        vector<int> result;

        for(auto it : freq) {
            int s = it.second;

            if(s > size) {   
                result.push_back(it.first);
            }
        }

        return result;
    }
};