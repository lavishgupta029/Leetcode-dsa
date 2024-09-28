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
    TreeNode* invert(TreeNode* root){
        if(root!=NULL){
            invert(root->left);
            invert(root->right);
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        return root;
    }
    bool isEqual(TreeNode* tree, TreeNode* invertTree){
        if(!tree && !invertTree) return true;
        if(!tree || !invertTree) return false;
        return tree->val==invertTree->val && isEqual(tree->left,invertTree->right) && isEqual(tree->right,invertTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        // TreeNode* invertTree=invert(root);
        return isEqual(root,root);
    }
};