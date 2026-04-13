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
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* initial=NULL;
    void makeParent(TreeNode* root,int start){
        if(root==NULL) return;
        if(!initial && root->val==start){
            initial=root;
        }
        if(root->left) parent[root->left]=root;
        makeParent(root->left,start);
        if(root->right) parent[root->right]=root;
        makeParent(root->right,start);

    }
    int amountOfTime(TreeNode* root, int start) {
        
        if(!root->left && !root->right) return 0;
        unordered_map<TreeNode*, bool> visited; 
        makeParent(root,start);
        queue<TreeNode*> q;
        q.push(initial);
        visited[initial]=true;
        int result=0;
        cout<<initial->val;
        while(!q.empty()){
            int count=q.size();
            while(count--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr] && !visited[parent[curr]]){
                    q.push(parent[curr]);
                    visited[parent[curr]]=true;
                }   
            }
            result++;
            
        }
        return result-1;

    }
};