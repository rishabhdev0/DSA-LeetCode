class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>seen;
        unordered_set<char>counted;
        for(char ch : word){
            if(islower(ch)){
                seen.insert(ch);
            }
        }

        int specialCount = 0;

        for(char& ch : word){
            if(isupper(ch)){
                char lower = tolower(ch);
                if(seen.count(lower) && !counted.count(lower)){
                    specialCount++;
                    counted.insert(lower);
                }
            }
        }
        return specialCount;
    }
};