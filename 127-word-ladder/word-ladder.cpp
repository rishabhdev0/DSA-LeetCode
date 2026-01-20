class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1; 

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                string word = q.front();
                q.pop();

                if (word == endWord) return level;

                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == original) continue;

                        word[i] = ch;

                        if (dict.find(word) != dict.end()) {
                            q.push(word);
                            dict.erase(word); // mark visited
                        }
                    }

                    word[i] = original; // restore
                }
            }
            level++;
        }
        return 0;
    }
};
