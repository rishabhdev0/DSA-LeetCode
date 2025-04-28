class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> result(26, 0);
        int max_len = 0;
       int max_count = 0;
        int i = 0;
        for(int j = 0; j< n;j++){
         result[s[j] -'A']++;
         max_count = max(max_count , result[s[j]-'A']);
         while(j-i+1 - max_count > k){
          result[s[i] - 'A']--;
          i++;
         }
         max_len = max(max_len , j-i+1);
        }
        return max_len;
    }
};