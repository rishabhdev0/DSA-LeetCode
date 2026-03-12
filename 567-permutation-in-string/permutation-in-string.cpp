class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<int>freq(26 , 0);
        vector<int>win_freq(26 , 0);
        for(auto &ch : s1){
            freq[ch - 'a']++;
        }

        int i = 0;
        int j = 0;

        while(j < m){
            win_freq[s2[j] - 'a']++;
            if(j - i + 1 > n){
                win_freq[s2[i] -'a']--;
                i++;
            }
            if(j - i + 1 == n && win_freq == freq){
                return true;
            }
            j++;
        }
        return false;
    }
};