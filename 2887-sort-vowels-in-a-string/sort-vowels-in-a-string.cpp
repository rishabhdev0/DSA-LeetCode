#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isVowel(char ch) {
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
                ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

public:
    string sortVowels(string s) {
        multiset<char> st;  // allows duplicates & keeps sorted order
        int n = s.length();
        for (int i = 0 ; i < n ; i++) {
            if (isVowel(s[i])) {
                st.insert(s[i]);
            }
        }

        // replace vowels with sorted ones
        auto it = st.begin();
        for (int i = 0; i < n ; i++) {
            if (isVowel(s[i])) {
                s[i] = *it;  // take next smallest vowel
                it++;
            }
        }

        return s;
    }
};
