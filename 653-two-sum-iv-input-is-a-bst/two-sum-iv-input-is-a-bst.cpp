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
    vector<int> temp;

    void dfs(TreeNode* root) {
        if(root == nullptr) return;
        dfs(root->left);
        temp.push_back(root->val);   // in-order traversal sorted values
        dfs(root->right);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int left = 0, right = temp.size() - 1;
        while(left < right) {
            int sum = temp[left] + temp[right];
            if(sum == k) return true;
            else if(sum > k) right--;
            else left++;
        }
        return false;
    }
};
