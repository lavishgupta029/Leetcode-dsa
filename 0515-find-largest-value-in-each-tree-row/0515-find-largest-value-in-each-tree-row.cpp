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
    map<int,int> mp;
    void helper(TreeNode* root, int level){

        if(root==NULL) return;
        if(mp.find(level)!=mp.end()){
            if(mp[level]<root->val){
                mp[level]=root->val;
            }
        }
        else{
            mp[level]=root->val;
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        int level=0;
        helper(root,level);
        for(auto ele: mp){
            result.push_back(ele.second);
        }
        return result;
    }
};