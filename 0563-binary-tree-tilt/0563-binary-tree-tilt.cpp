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
    int tilt=0;
    int helper(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;
        int left=helper(root->left);
        int right=helper(root->right);
        tilt += abs(left-right);
        return left+right+root->val;

    }
    int findTilt(TreeNode* root) {
        helper(root);
        return tilt;
        
    }
};