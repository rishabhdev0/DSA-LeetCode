class Solution {
public:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
        if (index >= digits.length()) {
            ans.push_back(output); 
            return;
        }

        int number = digits[index] - '0';  
        string value = mapping[number];  
        
        for (int i = 0; i < value.length(); i++) {
            output.push_back(value[i]);  
            solve(digits, output, index + 1, ans, mapping); // ind + 1 
            // because we get "a" + now next string "d" = "ad";
            output.pop_back(); // for backtrack  
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;  // To store the final combinations
        string output;  // Temporary string to store current combination
        int index = 0;  // Start from the first digit
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.empty()) return ans; 
        
        solve(digits, output, index, ans, mapping);  
        return ans;
    }
};