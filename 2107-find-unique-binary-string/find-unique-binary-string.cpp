// class Solution {
// public:
//     string result = "";

//     void backtracking(int idx , vector<string>& nums , unordered_set<string>& seen , string temp){
//         if(idx == nums.size()){
//            if(seen.find(temp) == seen.end()){
//               result = temp;
//            }
//            return;
//         }
//         temp.push_back('0');
//         backtracking(idx + 1 ,  nums , seen , temp);
//         temp.pop_back();

//         temp.push_back('1');
//         backtracking(idx + 1 , nums , seen , temp);
//         temp.pop_back();
//     }
//     string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums.size();
//         unordered_set<string>seen(nums.begin() , nums.end());
//         string temp = "";
//         backtracking(0 , nums , seen , temp);
//         return result;
//     }
// };


// trying the optimal solution only optimal when size == n same 

// class Solution {
// public: 
//     string findDifferentBinaryString(vector<string>& nums) {
//         int n = nums.size();
//         string result = "";
//         for(int i = 0 ; i < n ; i++){
//             if(nums[i][i] == '0') result += '1';
//             else result += '0';
//         }
//         return result;
//     }
// };

// now the good approach ;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int>seen;
        for(int i = 0 ; i < n ; i++){
           int num = stoi(nums[i] , nullptr , 2);
            seen.insert(num);
        }

        for(int i = 0  ; i < (1 << n) ; i++){
           if(seen.count(i) == 0){
                 string ans = bitset<16>(i).to_string();
                 return ans.substr(16 - n);
            }
        }
        return "";
    }
};
 