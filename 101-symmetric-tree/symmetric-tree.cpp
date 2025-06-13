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
private:
    bool is_symmetric(TreeNode* leftsub, TreeNode* rightsub) {
        if (leftsub == nullptr && rightsub == nullptr)
            return true;

        if (leftsub == nullptr || rightsub == nullptr)
            return false;

        if (leftsub->val != rightsub->val)
            return false;

        return is_symmetric(leftsub->left, rightsub->right) &&
               is_symmetric(leftsub->right, rightsub->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        return is_symmetric(root->left, root->right);
    }
};
