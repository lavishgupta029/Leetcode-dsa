class Solution {
public:
    bool isValid(int row,int col,vector<string> board,int n){
        int dupRow=row;
        int dupCol=col;
        while(dupRow>=0 && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupRow--;
            dupCol--;
        }
        dupRow=row;
        dupCol=col;
        while(dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupCol--;
        }
        dupRow=row;
        dupCol=col;
        while(dupRow<n && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupCol--;
            dupRow++;
        }
        return true;
    }
    void helper(int col, vector<vector<string>> &ans, vector<string> board, int n ){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isValid(row,col,board,n)){
                board[row][col]='Q';
                helper(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        helper(0,ans,board,n);
        return ans;
    }
};