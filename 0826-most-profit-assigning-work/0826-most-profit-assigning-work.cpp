class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int result=0;
        vector<pair<int,int>> vec;
        for(int i=0;i<profit.size();i++){
            int prof=profit[i];
            int diff=difficulty[i];
            vec.push_back({diff,prof});
        }
        sort(begin(vec),end(vec));
        for(int i=1;i<profit.size();i++){
            vec[i].second=max(vec[i-1].second,vec[i].second);
        }

        for(int i=0;i<worker.size();i++){
            int l=0;
            int r=vec.size();
            int currProfit=0;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(vec[mid].first<=worker[i]){
                    currProfit=max(currProfit,vec[mid].second);
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            result+= currProfit; 
        }
        return result;

        
    }
};