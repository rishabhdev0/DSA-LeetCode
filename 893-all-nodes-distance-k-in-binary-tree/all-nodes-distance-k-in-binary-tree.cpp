/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;

    void InOrder(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left) parent[root->left] = root;
        InOrder(root->left);
        if (root->right) parent[root->right] = root;
        InOrder(root->right);
    }

    void bfs(TreeNode* target, int k, vector<int>& result) {
        queue<TreeNode*> que;
        unordered_set<TreeNode*> visited;
          // mapping parent
        que.push(target);
        visited.insert(target);

        while (!que.empty()) {
            int n = que.size();
            if (k == 0) break;

            for (int i = 0; i < n; ++i) {
                TreeNode* curr = que.front();
                que.pop();
                //    left
                if (curr->left && !visited.count(curr->left)) {
                    que.push(curr->left);
                    visited.insert(curr->left);
                }
                  //right
                if (curr->right && !visited.count(curr->right)) {
                    que.push(curr->right);
                    visited.insert(curr->right);
                }
                   // parent
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            k--;
        }

        while (!que.empty()) {
            result.push_back(que.front()->val);
            que.pop();
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        InOrder(root);
        bfs(target, k, result);
        return result;
    }
};
