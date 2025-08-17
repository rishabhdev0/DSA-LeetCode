class Solution {
public:
    int k = 3; 
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(26, 0); 
        int i = 0, j = 0, result = 0;
        int count = 0;       

        while (j < n) {
            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1) {
                count++; 
            }

            while (count == k) {
                result += n - j; 

                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0) {
                    count--; 
                }
                i++;
            }

            j++;
        }

        return result;
    }
};
