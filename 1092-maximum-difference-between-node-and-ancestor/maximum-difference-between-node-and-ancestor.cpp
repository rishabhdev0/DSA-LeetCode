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
    int max_path(TreeNode* root , int minV , int maxV){
        if(root==nullptr){
            return abs(maxV - minV);
        }
        maxV = max(maxV , root->val);
        minV = min(minV , root->val);

        int left = max_path(root->left , minV ,maxV);
        int right = max_path(root->right ,minV , maxV);

        return max(left , right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return max_path(root , root->val , root->val);
    }
};