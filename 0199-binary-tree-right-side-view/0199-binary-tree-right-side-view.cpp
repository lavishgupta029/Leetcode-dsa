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
    int level=1;
    void preOrder(TreeNode* root,  vector<int> &result){
        if(root==NULL) return;

        if(result.size()<level){
            result.push_back(root->val);
        }
        level++;
        preOrder(root->right,result);

        preOrder(root->left,result);
        level--;
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root== NULL ) return {};
        vector<int> result;
        preOrder(root,result);
        return result;
    }
};