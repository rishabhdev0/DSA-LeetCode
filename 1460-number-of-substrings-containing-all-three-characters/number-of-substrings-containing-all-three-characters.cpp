class Solution {
public:
    int numberOfSubstrings(string s) {
       int n =  s.length();
       unordered_map< char , int> mp;
       int i = 0;
       int j=0;
       int result = 0;
       while(j<n){
        mp[s[j]]++;
        while(mp['a']>0 && mp['b']>0 && mp['c']>0){
            result+=n-j;
            mp[s[i]]--;
            i++;
        }
        j++;
       } 
       return result;
    }
};