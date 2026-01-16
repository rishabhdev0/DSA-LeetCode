class Trie {
public:
    struct trieNode {
        bool isEndWord;
        trieNode* children[26];
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->isEndWord = false;
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = nullptr;
        }
        return newNode;
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }

    void insert(string word) {
        trieNode* crawler = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == nullptr) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndWord = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return crawler->isEndWord;
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(crawler->children[idx] == nullptr) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        return true;
    }
};
