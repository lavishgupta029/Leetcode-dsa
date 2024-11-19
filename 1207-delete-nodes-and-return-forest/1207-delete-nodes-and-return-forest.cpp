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
    vector<TreeNode*> ans;
    void helper(TreeNode* root,bool is_root, unordered_set<int>& st){
        if(!root) return;
        if(st.count(root->val)){
            helper(root->left,true,st);
            helper(root->right,true,st);
        }

        else{
            if(is_root){
                ans.push_back(root);
            }
            TreeNode* leftNode=root->left;
            TreeNode* rightNode=root->right;
            if(root->left){
                if(st.count(root->left->val)){
                    root->left=NULL;
                }
            }
            
            if(root->right){
                if(st.count(root->right->val)){
                    root->right=NULL;
                }
            }
            helper(leftNode,false,st);
            helper(rightNode,false,st);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st;
        for(auto x: to_delete) st.insert(x);
        helper(root,true,st); 
        return ans;
    }
};