class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>word;
        string temp = "";
        for(char ch : s){
            if(ch == ' '){
                word.push_back(temp);
                temp = "";
            }else temp+=ch;
        }
        word.push_back(temp);
        if(pattern.length() != word.size()) return false;
        unordered_map<char , string>mp1;
        unordered_map<string , char>mp2;
        for(int i = 0 ; i < pattern.length() ; i++){
            char ch = pattern[i];
            string w = word[i];
            if(mp1.count(ch) && mp1[ch] != w) return false;
            if(mp2.count(w) && mp2[w] != ch) return false;
            mp1[ch] = w;
            mp2[w] = ch;
        }
        return true;
    }
};