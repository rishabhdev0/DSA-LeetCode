class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count frequency of each number
        for (auto& num : arr) {
            freq[num]++;
        }
        
        int ans = -1;

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];
            if (freq[num] == num) {
                ans = max(ans, num);  
            }
        }

        return ans;
    }
};
