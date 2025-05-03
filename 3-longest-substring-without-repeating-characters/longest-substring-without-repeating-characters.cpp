class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
         unordered_map< char , int > mp;
         int i = 0;
         int j = 0;
         int result = 0;
         while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            j++;
            result=max(result , j-i);
         }
         return result;
    }
};