class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int>freq(26 , 0);
        int i = 0;
        int j = 0; 
        int result = 0;
        while(j < n){
            freq[s[j] - 'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0){
                result += n - j;
                freq[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        return result;
    }
};