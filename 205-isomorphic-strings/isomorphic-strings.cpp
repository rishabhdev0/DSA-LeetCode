class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sToT; // mapping s -> t
        unordered_map<char, char> tToS; // mapping t -> s
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            char st = s[i];
            char tt = t[i];
            
            // Check if mapping conflicts exist
            if((sToT.find(st) != sToT.end() && sToT[st] != tt) || 
               (tToS.find(tt) != tToS.end() && tToS[tt] != st)) {
                return false;
            }
            
            sToT[st] = tt;
            tToS[tt] = st;
        }
        return true;
    }
};