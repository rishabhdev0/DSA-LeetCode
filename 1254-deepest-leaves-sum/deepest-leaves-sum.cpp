class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root == nullptr) return 0;

        int sum = 0;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();
            sum = 0;  // reset sum for this level

            for(int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                que.pop();

                sum += node->val;

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return sum;  
    }
};
