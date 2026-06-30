class Solution {
public:
    string result = "";

    void backtracking(int idx , vector<string>& nums , unordered_set<string>& seen , string temp){
        if(idx == nums.size()){
           if(seen.find(temp) == seen.end()){
              result = temp;
           }
           return;
        }
        temp.push_back('0');
        backtracking(idx + 1 ,  nums , seen , temp);
        temp.pop_back();

        temp.push_back('1');
        backtracking(idx + 1 , nums , seen , temp);
        temp.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>seen(nums.begin() , nums.end());
        string temp = "";
        backtracking(0 , nums , seen , temp);
        return result;
    }
};