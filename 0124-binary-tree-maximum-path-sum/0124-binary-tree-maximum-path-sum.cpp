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
    int result=INT_MIN;

    int helper(TreeNode *root){
        if(!root) return 0;

        int leftMax=max(0, helper(root->left));
        int rightMax= max(0, helper(root->right));
        result=max(result, root->val+leftMax+rightMax);
        return max(leftMax,rightMax)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return result;
    }
};