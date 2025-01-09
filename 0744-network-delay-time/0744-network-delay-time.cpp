class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto time: times){
            adj[time[0]].push_back({time[1],time[2]});
        }
        vector<int> dist(n+1,1e9);
        vector<int> vis(n+1,false);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            // int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=true;
            for(auto it: adj[node] ){
                int adjNode=it.first;
                int edgeWeight=it.second;
                if(dist[node]+edgeWeight<dist[adjNode]){
                    dist[adjNode]=dist[node]+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        if(ans==1e9) return -1;
        return ans;
    }
};