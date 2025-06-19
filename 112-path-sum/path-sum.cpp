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
    bool inOrder(TreeNode* root, int& targetSum, int sum) {
        if (root == nullptr) return false;
        
        sum += root->val;
        
        // if we reached the  leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return sum == targetSum;
        }

        bool left = inOrder(root->left, targetSum, sum);
        bool right = inOrder(root->right, targetSum, sum);
        
        return left || right;  
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return inOrder(root, targetSum, sum);
    }
};
