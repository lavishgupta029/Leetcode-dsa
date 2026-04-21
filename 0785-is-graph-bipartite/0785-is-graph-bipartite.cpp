class Solution {
public:
    bool isBipartiteDFS(int u, vector<vector<int>>& graph, vector<int>& color, int currColour){
        color[u]=currColour;

        for(auto &v : graph[u]){
            if(color[v]==currColour) return false;
            else if(color[v]==-1){
                int colorV=1-currColour;
                if(isBipartiteDFS(v,graph,color, colorV)== false) return false;
            }
        }
        return true;
    }
    bool isBipartiteBFS(int u, vector<vector<int>>& graph, vector<int>& color, int currColour){
        color[u]=currColour;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto &v: graph[curr]){
                if(color[v]==color[curr]) return false;
                else if(color[v]==-1){
                    color[v]=1-color[curr];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if( color[i]==-1 && !isBipartiteBFS(i,graph,color,0)){
                return false;
            }
        }
        return true;

    }
};