class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int>seen;

        for(int i = 0 ; i < n ; i++){
            int num = stoi(nums[i] , nullptr , 2);
            seen.insert(num);
        }
        for(int i = 0 ; i < (1 << n) ; i++){
            if(seen.count(i) == 0){ // not present in the set
                string sub = bitset<16>(i).to_string();
                return sub.substr(16 - n);
            }
        }
        return "";
    }
};