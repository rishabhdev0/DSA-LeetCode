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
    int dfs(TreeNode* root , int curr){
        if(root == nullptr) return 0;
        curr = (curr*10) + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return curr;
        }
        int left = dfs(root->left , curr);
        int right = dfs(root->right , curr);
        return left + right;
    }
public:
    int sumNumbers(TreeNode* root) {
        int curr = 0;
       return dfs(root, curr);
    }
};