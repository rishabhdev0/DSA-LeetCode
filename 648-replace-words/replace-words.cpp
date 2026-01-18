class Solution {
public:
    struct TrieNode {
        bool EndWord;
        TrieNode* children[26];

        TrieNode() {
            EndWord = false;
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };

    TrieNode* root;

    void insert(string word) {
        TrieNode* crawler = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(!crawler->children[idx])
                crawler->children[idx] = new TrieNode();
            crawler = crawler->children[idx];
        }
        crawler->EndWord = true;
    }

    string searchRoot(string word) {
        TrieNode* crawler = root;
        string prefix = "";

        for(char ch : word) {
            int idx = ch - 'a';
            if(!crawler->children[idx])
                return word;        // no root found
            prefix += ch;
            crawler = crawler->children[idx];
            if(crawler->EndWord)
                return prefix;     // find the shorest prefix
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new TrieNode();

        for(string &word : dictionary)
            insert(word);

        stringstream ss(sentence);
        string word, result = "";

        while(ss >> word) {
            result += searchRoot(word) + " ";
        }

        result.pop_back(); // remove last space
        return result;
    }
};
