class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<n;i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            if(!Union(x,y)) return {x,y};
        }
        return {};
    }
    int find(int i){
        if(parent[i]!=i){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }
    bool Union(int x,int y){
        int parentX=find(x);
        int parentY=find(y);
        if(parentX==parentY) return false;
        int rankX=rank[parentX];
        int rankY=rank[parentY];
        if(rankX>rankY){
            parent[parentY]=parentX;
        }
        else if(rankY>rankX){
            parent[parentX]=parentY;
        }
        else{
            parent[parentX]=parentY;
            rank[parentY]++;
        }
        return true;
    }
};