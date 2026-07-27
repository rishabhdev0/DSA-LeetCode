class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        int max_len = 0;
        int i = 0;
        int j = 0;
        int cost = 0;

        while(j < n){
             cost += abs(s[j] - t[j]);

            while(cost > maxCost){
                int it_cost = abs(s[i] - t[i]);
                cost -= it_cost;
                i++;                
            }
            max_len = max(max_len , j - i +  1);
            j++;
        }
        return max_len;
    }
};