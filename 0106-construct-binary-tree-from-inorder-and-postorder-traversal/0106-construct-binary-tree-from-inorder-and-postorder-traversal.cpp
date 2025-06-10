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
    int postIndex;
    TreeNode* helper(int start,int end,vector<int>& inorder, vector<int>& postorder){
        if(start>end) return NULL;
        TreeNode* root=new TreeNode(postorder[postIndex]);
        int inIndex=0;
        for(int i=start;i<=end;i++){
            if(postorder[postIndex]==inorder[i]){
                inIndex=i;
                break;
            }
        }    
        postIndex--;
        root->right=helper(inIndex+1,end,inorder,postorder);
        root->left=helper(start,inIndex-1,inorder,postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex=inorder.size()-1;
        return helper(0,postIndex,inorder,postorder);
    }
};