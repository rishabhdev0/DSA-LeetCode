class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int>freq(26 , 0);
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int del = 0;
        unordered_set<int>unique;
        for(int i = 0 ; i < 26 ; i++){
            while(freq[i] > 0 && unique.count(freq[i])){
                del++;
                freq[i]--;
            }
            unique.insert(freq[i]);
        }
        return del;
    }
};