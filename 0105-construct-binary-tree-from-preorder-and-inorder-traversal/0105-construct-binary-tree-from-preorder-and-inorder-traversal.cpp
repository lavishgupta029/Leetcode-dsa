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
    int preIndex=0;
    TreeNode* build(int start, int end,vector<int>& preorder, vector<int>& inorder ){
        if(start> end) return NULL;
        int rootVal=preorder[preIndex];
        preIndex++;
        int inIndex=-1;
        for(int i=start;i<=end;i++){
            if(inorder[i]==rootVal){
                inIndex=i;
                break;
            }
        }
        TreeNode* root = new TreeNode(rootVal);
        root->left= build(start,inIndex-1,preorder,inorder);
        root->right= build(inIndex+1, end, preorder, inorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(0,preorder.size()-1, preorder,inorder);
        
    }
};