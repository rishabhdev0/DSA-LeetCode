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
    private:
        TreeNode* convert(vector<int>& nums , int start , int end){
            if(start > end){
                return nullptr;
            }
            int mid = start + (end - start)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = convert(nums , start , mid-1);
            root->right = convert(nums , mid+1 , end);
           return root;
        }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return convert(nums , 0 , n-1);

    }
};