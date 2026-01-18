class Solution {
public:
    struct TrieNode {
        bool endWord;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode* node = new TrieNode();
        node->endWord = false;
        for(int i = 0; i < 26; i++)
            node->children[i] = nullptr;
        return node;
    }

    TrieNode* root;

    void insert(string word) {
        TrieNode* crawler = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(!crawler->children[idx]) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->endWord = true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";

        root = getNode();

        for(string &str : strs) {
            insert(str);
        }

        string prefix = "";
        TrieNode* crawler = root;

        while(true) {
            int childCount = 0;
            int nextIndex = -1;

            for(int i = 0; i < 26; i++) {
                if(crawler->children[i]) {
                    childCount++;
                    nextIndex = i;
                }
            }

            // Stop if more than one child OR end of word
            if(childCount != 1 || crawler->endWord)
                break;

            prefix.push_back(nextIndex + 'a');
            crawler = crawler->children[nextIndex];
        }

        return prefix;
    }
};
