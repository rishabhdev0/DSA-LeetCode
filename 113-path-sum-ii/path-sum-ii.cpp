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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, 0, path, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int target, long long currSum, vector<int>& path, vector<vector<int>>& result) {
        if (!node) return;

        currSum += node->val;
        path.push_back(node->val);

        // If it's a leaf
        if (!node->left && !node->right) {
            if (currSum == target) {
                result.push_back(path);
            }
        } else {
            dfs(node->left, target, currSum, path, result);
            dfs(node->right, target, currSum, path, result);
        }

        path.pop_back(); 
    }
};
