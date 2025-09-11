class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string sortVowels(string s) {
        int n = s.length();
        string vowels = "";

        // collect all vowels
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                vowels += s[i];
            }
        }

        // sort the vowels
        sort(vowels.begin(), vowels.end());

        // place them back in sorted order
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};
