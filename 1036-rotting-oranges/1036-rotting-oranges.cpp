class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        int counter=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                    
                }
                else if(grid[i][j]==1){
                    counter++;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;

            q.pop();
            ans=max(ans,t);
            vector<int> x={-1,1,0,0};
            vector<int> y={0,0,-1,1};
            for(int i=0;i<4;i++){
                int newRow=row+x[i];
                int newCol=col+y[i];
                if(newRow<m && newCol<n && newRow>=0 && newCol>=0 && visited[newRow][newCol]==0 && grid[newRow][newCol]==1){
                    q.push({{newRow,newCol},t+1});
                    visited[newRow][newCol]=1;
                    counter--;
                }
            }
        }
        if(counter!=0) return -1;
        return ans;
    }
};