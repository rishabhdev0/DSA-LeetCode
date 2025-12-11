class Solution {
public:
    struct TrieNode {
        TrieNode* left;  // represents bit 0
        TrieNode* right; // represents bit 1
        TrieNode() : left(nullptr), right(nullptr) {}
    };
    
    void insert(TrieNode* root, int num) {
        TrieNode* crawl = root;
        for(int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;  
            
            if(ith_bit == 0) {
                if(crawl->left == nullptr) {
                    crawl->left = new TrieNode();
                }
                crawl = crawl->left;
            } else {
                if(crawl->right == nullptr) {
                    crawl->right = new TrieNode();
                }
                crawl = crawl->right;
            }
        }
    }
    
    int maxXor(TrieNode* root, int num) {
        TrieNode* crawl = root;
        int currentXor = 0;
        
        for(int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;
            
            if(ith_bit == 0) {
                if(crawl->right != nullptr) {
                    currentXor |= (1 << i);  // Set this bit in result
                    crawl = crawl->right;
                } else {
                    crawl = crawl->left;  // Have to take 0
                }
            } else {
                if(crawl->left != nullptr) {
                    currentXor |= (1 << i);  
                    crawl = crawl->left;
                } else {
                    crawl = crawl->right;  // Have to take 1
                }
            }
        }
        return currentXor;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        
        TrieNode* root = new TrieNode(); 
        for(int num : nums) {
            insert(root, num);
        }
        
        int maxVal = 0;
        for(int num : nums) {  
            int val = maxXor(root, num);
            maxVal = max(maxVal, val);
        }
        return maxVal;
    }
};