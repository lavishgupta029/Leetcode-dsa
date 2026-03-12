class Solution {
public:
    vector<string> result;
    bool isValid(string curr){
        int count=0;

        for(auto &ch: curr){
            if(ch=='('){
                count++;
            }
            else{
                count--;
            }
            if(count<0) return false;
        }
        return count==0;
    }
    void helper(string &curr, int open, int close, int n){
        if(open>n || close>open) return;
        if(curr.length() == 2*n){
            if(isValid(curr)){
                result.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        helper(curr,open+1,close,n);
        curr.pop_back();
        curr.push_back(')');
        helper(curr,open,close+1,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0,close=0;
        helper(curr,open,close, n);
        return result;
    }
};