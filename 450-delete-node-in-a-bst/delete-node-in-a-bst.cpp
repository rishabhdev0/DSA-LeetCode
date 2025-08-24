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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // Case 1: Node is a leaf (no children)
            if (root->left == nullptr && root->right == nullptr) {
                return nullptr;
            }
            // Case 2: Node has only one child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                return temp;
            }
            else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                return temp;
            }
            // Case 3: Node has two children
            // Take left child
            TreeNode* leftChild = root->left;

            // Find the rightmost node in left subtree
            TreeNode* temp = leftChild;
            while (temp->right != nullptr) {
                temp = temp->right;
            }

            // Attach right subtree to that node
            temp->right = root->right;

            // Replace root with its left child
            return leftChild;
        }

        return root; // no key is found
    }
};
