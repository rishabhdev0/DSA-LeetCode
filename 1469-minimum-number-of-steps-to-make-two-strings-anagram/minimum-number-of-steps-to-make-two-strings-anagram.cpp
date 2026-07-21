class Solution {
public:
    int minSteps(string s, string t) {
         vector<int>freq(26 , 0);
         for(int i = 0 ; i < s.length() ; i++){
            freq[s[i] - 'a']++;
         }
         int n = t.length();
         int Count = 0;
         for(int i = 0 ; i < n ; i++){
            int index = t[i] - 'a';
            if(freq[index] > 0){
                freq[index]--;
            }else{
                Count++;
            }
         }
         return Count;
    }
};