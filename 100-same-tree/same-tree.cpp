class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        
        queue<pair<TreeNode*, TreeNode*>> que;
        que.push({p, q});
        
        while (!que.empty()) {
            auto pr = que.front(); que.pop();
            TreeNode* a = pr.first;
            TreeNode* b = pr.second;
            
            if (a == nullptr && b == nullptr) continue;
            if (a == nullptr || b == nullptr) return false;
            if (a->val != b->val) return false;
            
            // push corresponding children for later comparison
            que.push({a->left,  b->left});
            que.push({a->right, b->right});
        }
        
        return true;
    }
};
