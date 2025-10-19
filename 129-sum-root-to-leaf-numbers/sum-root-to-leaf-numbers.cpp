class Solution {
private:
    int dfs(TreeNode* root, int sum) {
        if (root == nullptr) return 0;

        sum = sum * 10 + root->val;

        // If it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return sum;
        }

        // Recurse left and right
        int left = dfs(root->left, sum);
        int right = dfs(root->right, sum);

        return left + right;
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        return dfs(root, sum); 
    }
};