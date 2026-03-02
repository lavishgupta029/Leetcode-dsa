class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> mp;
        for(auto num: nums){
            mp[num]++;
        }
        for(auto &ele : mp){
            pq.push({ele.second,ele.first});
        }
        while(k>0){
            int ele=pq.top().second;
            pq.pop();
            result.push_back(ele);
            k--;
        }
        return result;

    }
};