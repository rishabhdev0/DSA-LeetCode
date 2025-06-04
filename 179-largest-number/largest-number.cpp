class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto MyComparator = [](int& a, int& b) {
            string s1 = to_string(a); //convert in into string;
            string s2 = to_string(b); // convert int into string;
            if (s1 + s2 > s2 + s1) {  // which one is getting bigger answer;
                return true;
            } else {
                return false;
            }
        }; 

        sort(nums.begin(), nums.end(), MyComparator);
        
         if (nums[0] == 0) return "0";

        string result = "";
        for (int num : nums) {
            result += to_string(num); // adding to the result of string
        }
        return result;
    }
};
