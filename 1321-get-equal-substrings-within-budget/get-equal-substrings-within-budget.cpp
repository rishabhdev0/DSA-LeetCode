class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int max_length = 0;
        int cost = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            cost += abs(s[j] - t[j]);  
            if(cost > maxCost) { 
                cost -= abs(s[i] - t[i]);
                i++;
            }
            max_length = max(max_length, j - i + 1);  
            j++;
        }
        return max_length;
    }
};