class Solution {
public:
    void dfs(int u, vector<bool> &visited, vector<vector<int>> adj){
        if(visited[u]) return;
        visited[u]=true;

        for(auto v: adj[u]){
            if(!visited[v]){
                dfs(v,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int result=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                result++;
                dfs(i,visited,adj);
            }
        }
        return result;
    }
};