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
    int maxPath=0;
    void helper(TreeNode* root, int steps, bool isLeft){

        if(root==NULL) return;
        maxPath=max(maxPath,steps);
        if(isLeft){
            helper(root->left,steps+1,false);
            helper(root->right,1,true);
        }
        else{
            helper(root->right,steps+1,true);
            helper(root->left,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        
        helper(root, 0, false);
        helper(root,0, true);
        return maxPath;
    }
};