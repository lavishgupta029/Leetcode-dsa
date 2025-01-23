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
    bool helper(TreeNode* root,TreeNode*min,TreeNode*max){
        if(root==NULL) return true;
        if(min && root->val>=min->val) return false;
        if(max && root->val<=max->val) return false;
        bool left=helper(root->left,root,max);
        bool right=helper(root->right,min,root);
        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        return helper(root,NULL,NULL);
    }
};