class Solution {
public:
    string removeDuplicates(string s) {
        int st = 0; 
        for (int i = 0; i < s.length(); i++) {
            // If the current character is the same as the previous one, skip it
            if (st > 0 && s[st - 1] == s[i]) {
                st--; 
            } else {
                s[st] = s[i];  
                st++;  
            }
        }
        return s.substr(0, st);
    }
};
