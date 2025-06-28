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
    int maxDifference;

    // Compare ancestorNode with all its descendants
    void compareWithDescendants(TreeNode* ancestorNode, TreeNode* descendantNode) {
        if (ancestorNode == nullptr || descendantNode == nullptr) return;

        int currentDiff = abs(ancestorNode->val - descendantNode->val);
        maxDifference = max(maxDifference, currentDiff);

        compareWithDescendants(ancestorNode, descendantNode->left);
        compareWithDescendants(ancestorNode, descendantNode->right);
    }

    // For each node, treat it as an ancestor and compare with all descendants
    void traverseTree(TreeNode* currentNode) {
        if (currentNode == nullptr) return;

        compareWithDescendants(currentNode, currentNode->left);
        compareWithDescendants(currentNode, currentNode->right);

        traverseTree(currentNode->left);
        traverseTree(currentNode->right);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        maxDifference = -1;
        traverseTree(root);
        return maxDifference;
    }
};
