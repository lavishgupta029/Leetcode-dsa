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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int currLevel=0, result=0,maxSum=INT_MIN;
        while(!q.empty()){
            currLevel++;
            int count=q.size();
            int currLevelSum=0;
            for(int i=0;i<count;i++){
                TreeNode *curr=q.front();
                q.pop();
                currLevelSum += curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }   
            if(maxSum<currLevelSum){
                maxSum=currLevelSum;
                result=currLevel;
            }
        }
        return result;
    }
};