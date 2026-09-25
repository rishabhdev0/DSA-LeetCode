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
    int maxSum;

    int solve(TreeNode*  root){
         if(root == nullptr) 
            return 0;
        
        int left = solve(root->left);
        int right = solve(root -> right);

        int we_get_best_answer_here = left+ right + root->val; // we will not explore further
        int only_get_best = max(left , right) + root->val;
        int only_root = root->val;

        maxSum = max(maxSum , max({we_get_best_answer_here , only_get_best , only_root}));

        // we can only expore the 
        return max(only_get_best , only_root);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};