class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> result;
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            TreeNode* node = nullptr;

            for (int i = 0; i < n; i++) {
                node = que.front();
                que.pop();

                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }

           // the nodes had the value of rightmost 
            result.push_back(node->val);
        }

        return result;
    }
};
