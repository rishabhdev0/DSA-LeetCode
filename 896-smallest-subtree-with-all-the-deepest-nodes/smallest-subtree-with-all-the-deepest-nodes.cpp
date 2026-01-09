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
    unordered_map<TreeNode*, int> mp;
    int maxDepth = 0;

    void Depth(TreeNode* root, int d) {
        if (!root) return;

        maxDepth = max(maxDepth, d);
        mp[root] = d;

        Depth(root->left, d + 1);
        Depth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (!root || mp[root] == maxDepth) {
            return root;
        }

        TreeNode* left = LCA(root->left);
        TreeNode* right = LCA(root->right);

        if (left && right) return root;
        return left ? left : right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        Depth(root, 0);
        return LCA(root);
    }
};
