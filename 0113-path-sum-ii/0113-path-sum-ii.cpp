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
    vector<vector<int>> result;
    void helper(TreeNode* root,vector<int> temp, int targetSum){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(!root->left && !root->right && root->val==targetSum){
            result.push_back(temp);
        }

       
        helper(root->left,temp,targetSum-root->val);
        helper(root->right,temp,targetSum-root->val);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        helper(root,temp, targetSum);

        return result;

    }
};