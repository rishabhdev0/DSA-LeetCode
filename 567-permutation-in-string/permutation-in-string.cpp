class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26 , 0);
        for(char ch : s1){
            freq[ch - 'a']++;
        }
        vector<int>window_freq(26 , 0);
        int i = 0;
        int j = 0;
        int n = s2.length();
        while(j < n){
           window_freq[s2[j] - 'a']++;
           if(j - i + 1 > s1.length()){
              window_freq[s2[i] - 'a']--;
              i++;
           }
           if(j - i + 1 == s1.length() && window_freq == freq){
            return true;
           }
           j++;
        }
        return false;
    }
};