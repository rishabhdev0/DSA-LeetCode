class Solution {
private:
    bool check_same(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;

        if (p == nullptr || q == nullptr) return false;

        if (p->val != q->val) return false;

        return check_same(p->left, q->left) && check_same(p->right, q->right);
    }

public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check_same(p, q);
    }
};