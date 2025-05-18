class Solution {
public:
    void backtrack(int open, int close, int n, vector<string> &ans, string str){
        if(open ==n && close == n){
            ans.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            backtrack(open+1,close,n, ans, str);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            backtrack(open,close+1,n,ans,str);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str="";
        backtrack(0,0,n,ans,str);
        return ans;
        }
};