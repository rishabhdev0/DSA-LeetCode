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
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int leftH = dfs(root->left);
        if(leftH == -1 )  return -1;
        int rightH = dfs(root->right);
        if(rightH == -1) return -1;
        if(abs(leftH - rightH)>1) return -1;
        return max(leftH, rightH) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};