class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        priority_queue<pair<int,pair<int,int>>> pq;

        int m=nums1.size();
        int n=nums2.size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum =nums1[i]+nums2[j];
                
                if(pq.size()<k){
                    pq.push({sum,{i,j}});
                }
                else if(pq.top().first>sum){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else{
                    break;
                }
            }
        }
        while(k>0){
            pair<int,pair<int,int>> ele=pq.top();
            int x=ele.second.first;
            int y=ele.second.second;
            pq.pop();
            result.push_back({nums1[x],nums2[y]});
            k--;
        }
        return result;
    }
};