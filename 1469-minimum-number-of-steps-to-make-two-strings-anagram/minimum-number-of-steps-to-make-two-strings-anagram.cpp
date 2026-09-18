class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.length();

        vector<int> freq(26, 0);

        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < t.length(); i++){
            freq[t[i] - 'a']--;
        }

        int count = 0;

        for(int i = 0; i < 26; i++){
           if(freq[i] < 0){ // not present in t
               count += abs(freq[i]);
           }
        }

        return count;
    }
};