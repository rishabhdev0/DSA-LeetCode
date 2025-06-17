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
    int minDepth(TreeNode* root) {
      //using bfs
      if(root==nullptr) return 0;
      queue<TreeNode*> que;
      que.push(root);
      int depth = 1;
      while(!que.empty()){
        int n = que.size();
        while(n--){
            TreeNode* temp = que.front();
            que.pop();
            if(temp->left  == nullptr && temp->right==nullptr){
                return depth;
            }
            if(temp->left != nullptr ){
                que.push(temp->left);
            }
            if(temp->right !=  nullptr){
                que.push(temp->right);
            }
        }
        depth++;
      }
    return depth;

    }
};