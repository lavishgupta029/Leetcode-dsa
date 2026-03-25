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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            return new TreeNode(val,root,NULL);
        }

        queue<TreeNode*> q;
        int currDepth=1;
        q.push(root);

        while(!q.empty() && currDepth<depth-1){
            int count=q.size();
            while(count){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                count--;
            }
            currDepth++;
        }

        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            TreeNode* currLeft=curr->left;
            TreeNode* currRight= curr->right;
            curr->left= new TreeNode(val);
            curr->right= new TreeNode(val);
            curr->left->left=currLeft;
            curr->right->right=currRight;
        }
        return root;
    }
};