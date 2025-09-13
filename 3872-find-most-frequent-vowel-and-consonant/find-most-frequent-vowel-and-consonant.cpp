class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch =='e' || ch=='i' || ch=='o' || ch=='u';
    }
public:
    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char, int> vowel;
        unordered_map<char, int> consonant;

        int vowel_Count = 0;
        int consonant_Count = 0;

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                vowel[s[i]]++;
                vowel_Count = max(vowel_Count, vowel[s[i]]);
            } else {
                consonant[s[i]]++;
                consonant_Count = max(consonant_Count, consonant[s[i]]);
            }
        }
        return vowel_Count + consonant_Count;
    }
};
