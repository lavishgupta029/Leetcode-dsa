class Solution {
public:
    vector<int> parent,rank;
    void Union(int x,int y){
        int parent_x=find(x);
        int parent_y=find(y);
        if(parent_x!= parent_y){
           
            if(rank[parent_x]>rank[parent_y]){
                parent[parent_y]=parent_x;
            }
            else if(rank[parent_x]<rank[parent_y]){
                parent[parent_x]=parent_y;
            }
            else{
                parent[parent_y]=parent_x;
                rank[parent_x]++;
            } 
        }

    }
    int find(int i){
        if(i!= parent[i]){
            parent[i]=find(parent[i]);
        }
        return parent[i];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
       parent.resize(n);
       rank.resize(n);
       for(int i=0;i<n;i++){
           parent[i]=i;
           rank[i]=1;
       }
       int totalThreads=connections.size();
       if(totalThreads<n-1) return -1;
       int components = n;
       for(auto connection: connections) {
            if(find(connection[0])== find(connection[1])) continue;
            components--;
            Union(connection[0],connection[1]);
       }
    //    for(int i=0;i<n;i++){
    //        cout<<parent[i];
    //    }
    //    unordered_set<int> st(parent.begin(),parent.end());
       return components-1;
    }
};