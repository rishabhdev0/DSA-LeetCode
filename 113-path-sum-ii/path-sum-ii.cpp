class Solution {
private:
    void inOrder(TreeNode* root , int sum , vector<int> temp , int targetSum, vector<vector<int>> &result) {
        if (root == nullptr) return;

        sum += root->val;
        temp.push_back(root->val);

        // If it's a leaf node
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                result.push_back(temp);
            }
            return;
        }

        inOrder(root->left , sum , temp, targetSum, result);
        inOrder(root->right , sum , temp, targetSum, result);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> temp;
        inOrder(root , 0 , temp, targetSum, result);
        return result;
    }
};
