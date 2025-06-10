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
    int find_diameter(TreeNode* root, int &maxi){
        if (root == nullptr) {
            return 0;
        }

        int lh = find_diameter(root->left, maxi);   // left height
        int rh = find_diameter(root->right, maxi);  // right height

        // update maximum diameter seen so far
        maxi = max(maxi, lh + rh);

        // return height of current node
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        find_diameter(root, maxi);
        return maxi;
    }
};
