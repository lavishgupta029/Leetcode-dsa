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
   
    bool bfs(vector<vector<int>> &adj, vector<int> &inDegree){
         int count=0;
        queue<int> q;
        for(int i=0;i<adj.size();i++ ){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            count++;
            int u=q.front();
            q.pop();

            for(auto &v: adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0) q.push(v);
            }
        }
        return count==adj.size();


    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n);
        for(auto v: prerequisites){
            adj[v[1]].push_back(v[0]);
            inDegree[v[0]]++;
        }
        vector<int> visited(n,false);
        vector<int> path(n,false);
        // for(int i=0;i<n;i++){
        //     if(!visited[i]){
        //         if() return false;
        //     }
        // }
        return bfs(adj, inDegree);
    }
};