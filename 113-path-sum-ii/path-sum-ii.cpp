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
    void inOrder(TreeNode* root, int sum, vector<int> temp, int targetSum,           vector<vector<int>>& result) {
        if (!root) return;
        sum += root->val;
        temp.push_back(root->val);

        if (!root->left && !root->right && sum == targetSum) {
            result.push_back(temp);
            return; // no more further recursion
        }

        inOrder(root->left, sum, temp, targetSum, result);
        inOrder(root->right, sum, temp, targetSum, result);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        inOrder(root, 0, {}, targetSum, result);
        return result;
    }
};
