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
    void helper(vector<int> path,vector<vector<int>> &ans, TreeNode* root,int targetSum){
        if(root==NULL) return;
        path.push_back(root->val);

        if(!root->left && !root->right && root->val==targetSum){
            ans.push_back(path);
            return;
        }
        helper(path,ans,root->left,targetSum-root->val);
        helper(path,ans,root->right,targetSum-root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(path,ans,root,targetSum);
        return ans;
    }
};