class Solution {
public:
    string removeKdigits(string num, int k) {
        string result; 
        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        
        // Remove remaining k digits from the end if needed
        result.resize(result.length() - k); //increasing order so we remove the greatest digit
        
        // Remove leading zeros
        int start = 0;
        while (start < result.length() && result[start] == '0') {
            start++;
        }
        
        result = result.substr(start);
        
        return result.empty() ? "0" : result;
    }
};