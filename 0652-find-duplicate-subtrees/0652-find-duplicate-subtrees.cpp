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
    vector<TreeNode*> res;
    string helper(TreeNode* root,  unordered_map<string,int> &mp){

        if(root==NULL) return "N";

        string curr= to_string(root->val)+","+ helper(root->left,mp)+","+helper(root->right,mp);

        if(mp[curr]==1){
            res.push_back(root);
        }
        mp[curr]++;

        return curr;

    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> mp;

        helper(root, mp);

        return res;

    }
};