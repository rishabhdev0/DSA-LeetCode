class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> seen;
        for (char c : brokenLetters) {  // FIXED this line
            seen.insert(c);
        }

        int count = 0;
        bool canType = true;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                if (canType) {
                    count++;
                }
                canType = true; // reset for the next word
            } else {
                if (seen.find(text[i]) != seen.end()) {
                    canType = false;
                }
            }
        }

        if (canType) count++; // check last word
        return count;
    }
};
