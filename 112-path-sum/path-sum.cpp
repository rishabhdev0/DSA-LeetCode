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
// class Solution {
// private:
//     bool inOrder(TreeNode* root, int& targetSum, int sum) {
//         if (root == nullptr) return false;
        
//         sum += root->val;
        
//         // if we reached the  leaf node
//         if (root->left == nullptr && root->right == nullptr) {
//             return sum == targetSum;
//         }

//         bool left = inOrder(root->left, targetSum, sum);
//         bool right = inOrder(root->right, targetSum, sum);
        
//         return left || right;  
//     }

// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         int sum = 0;
//         return inOrder(root, targetSum, sum);
//     }
// };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(root==nullptr) return false;
       queue<pair<TreeNode* , int>>que;
       que.push({root, root->val});
       while(!que.empty()){
        auto[node , currsum] = que.front();
        que.pop();
        // check if its leaf node
        if(node->left==nullptr &&node->right == nullptr){
            if(currsum == targetSum) return true;
        }
        if(node->left != nullptr){
            que.push({node->left , currsum + node->left->val});
        }
        if(node->right != nullptr){
            que.push({node->right , currsum + node->right->val});
        }
    }
return false;
    }
};

