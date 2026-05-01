class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n =  nums.size();
        sort(nums.begin() , nums.end() , [](int a , int b){
            string s_1 = to_string(a);
            string s_2 = to_string(b);
           return s_1 + s_2 > s_2 + s_1;
        });
        string result = "";
        for(int num : nums){
            result += to_string(num);
        }

         if(result[0] == '0') return "0";


        return result;
    }
};