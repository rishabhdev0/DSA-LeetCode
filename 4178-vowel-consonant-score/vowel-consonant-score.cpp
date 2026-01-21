class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel_count = 0;
        int const_count = 0;
        for(char ch  : s){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowel_count++;
            }else if(isalpha(ch)){
                const_count++;
            }
        }
        if(const_count == 0) return 0;
        return vowel_count / const_count;
    }
};