class Solution {
public:
    string largestGoodInteger(string nums) {
        string result = "";
        int n = nums.size();
        for(int i = 0 ; i < n-2 ; i++){
            if(nums[i]==nums[i+1] && nums[i]==nums[i+2]){
                string temp = nums.substr(i , 3);
                if(result < temp){
                    result = temp;
                }
            }
        }
        return result;
    }
};