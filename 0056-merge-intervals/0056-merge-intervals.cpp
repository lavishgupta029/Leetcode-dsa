class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int n= intervals.size();
        int i=0;
        sort(intervals.begin(),intervals.end());
        while(i<n){
            int j=i+1;
            int firstEle=intervals[i][0];
            int endEle=intervals[i][1];
            while(j<n && endEle>=intervals[j][0]){
                endEle=max(endEle, intervals[j][1]);
                j++;
            }
            result.push_back({firstEle,endEle});
            i=j;
        }
        return result;

    }
};