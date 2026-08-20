class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result(2);
        map<int,int> mp;

        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            mp[loser]++;
            if(mp.find(winner)==mp.end()){
                mp[winner]=0;
            }
        }
        for(auto &it: mp){
            if(it.second==0){
                result[0].push_back(it.first);
            }
            if(it.second==1){
                result[1].push_back(it.first);
            }
        }
        return result;
    }
};