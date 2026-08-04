class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int n=intervals.size();
        int k=0;
        while(k<n && intervals[k][1]<newInterval[0]){
            result.push_back(intervals[k]);
            k++;
        }
        int low=newInterval[0];
        int high=newInterval[1];
        while(k<n && intervals[k][0]<=high){
            low=min(low,intervals[k][0]);
            high=max(high,intervals[k][1]);
            k++;
        }
        result.push_back({low,high});
        while(k<n){
            result.push_back(intervals[k]);
            k++;
        }
        return result;
    }
};