class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        vector<vector<int>> result(2);

        for(auto &match: matches){
            mp[match[1]]++;
            if(mp.find((match[0]))==mp.end()){
                mp[match[0]]=0;
            }
        }   
        for(auto &scores: mp){
            if(scores.second==0){
                result[0].push_back(scores.first);
            }
            if(scores.second==1){
                result[1].push_back(scores.first);
            }
        }
        return result;
    }
};