class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, vector<pair<int, int>>> adjList;
        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

        for(auto time : times){
            adjList[time[0]].push_back({time[1],time[2]});
        }
        pq.push({0,k});
        distance[k]=0;

        while(!pq.empty()){
            int currEle=pq.top().second;
            int currWeight=pq.top().first;
            pq.pop();
            for(auto ele: adjList[currEle]){
                int nextEle=ele.first;
                int  nextWeight=ele.second;
                if(currWeight +  nextWeight <distance[nextEle]){
                    distance[nextEle]= currWeight +  nextWeight ;
                    pq.push({currWeight +  nextWeight, nextEle});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX) return -1;
            ans = max(ans,distance[i]);
        }
        return ans;

    }
};