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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == nullptr) return result;
        queue<TreeNode *> que;
        que.push(root);
        bool leftToRight = true;
        while(!que.empty()){
             int n = que.size();
             vector<int>temp(n);
             for(int i = 0 ; i < n ; i++){
                TreeNode* node = que.front();
                que.pop();
                int index = leftToRight ? i : (n - i - 1);
                temp[index] = node -> val;
                if(node -> left != nullptr){
                    que.push(node -> left);
                }
                if(node -> right != nullptr){
                    que.push(node -> right);
                }
             }
             result.push_back(temp);
             leftToRight = !leftToRight;
        }
        return result;
    }
};