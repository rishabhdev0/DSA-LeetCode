/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void buildNode(TreeNode* root, vector<int>& node) {
        if (root == nullptr) return;
        buildNode(root->left, node);
        node.push_back(root->val);
        buildNode(root->right, node);
    }

    TreeNode* balanceTree(vector<int>& node, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(node[mid]);

        root->left = balanceTree(node, start, mid - 1);
        root->right = balanceTree(node, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> node;
        buildNode(root, node);
        return balanceTree(node, 0, node.size() - 1);
    }
};
