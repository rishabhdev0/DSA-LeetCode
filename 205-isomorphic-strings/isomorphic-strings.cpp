class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char>mp1;
        unordered_map<char , char>mp2;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            char st = s[i];
            char tt = t[i];
            // have we map this before ? in both 
            if((mp1.find(st) != mp1.end() && mp1[st] !=  tt) ||
              (mp2.find(tt) != mp2.end() && mp2[tt] != st)){
                return false;
              }
              mp1[st] = tt;
              mp2[tt] = st;
        }
        return true;
    }
};