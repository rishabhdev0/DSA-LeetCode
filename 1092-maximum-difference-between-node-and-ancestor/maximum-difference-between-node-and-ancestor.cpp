class Solution {
public:
    int findMax(TreeNode* root , int maxV , int minV){
        if(root == nullptr){
            return abs(maxV - minV);
        }

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        int left = findMax(root->left, maxV, minV);
        int right = findMax(root->right, maxV, minV);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return findMax(root, root->val, root->val);
    }
};
