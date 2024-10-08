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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low=min(p->val,q->val);
        int high=max(p->val,q->val);
        while(root!=NULL){
            if(root->val<low) root=root->right;
            else if(root->val>high) root=root->left;
            else return root;

        }
        return NULL;
    }
};