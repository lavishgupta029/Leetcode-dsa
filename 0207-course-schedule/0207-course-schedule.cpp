class Solution {
public:
    bool dfs(int u, vector<int> &visited, vector<int> &path,vector<vector<int>> &adj){
        visited[u]=true;
        path[u]=true;
        for(auto v: adj[u]){
            if(path[v]) return true;
            else if(!visited[v]){
                if(dfs(v,visited,path,adj)) return true;
            }
        }

        path[u]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto v: prerequisites){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> visited(n,false);
        vector<int> path(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(i,visited,path,adj)) return false;
            }
        }
        return true;
    }
};