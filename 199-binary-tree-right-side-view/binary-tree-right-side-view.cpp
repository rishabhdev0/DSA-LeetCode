class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);

                if (i == n - 1) {  // last node make sure 
                    result.push_back(node->val);
                }
            }
        }
        return result;
    }
};