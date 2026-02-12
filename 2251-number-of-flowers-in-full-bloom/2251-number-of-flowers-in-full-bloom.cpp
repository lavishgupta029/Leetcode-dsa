class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> result;
        vector<int> start,end;
        for (auto flower: flowers){
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        for(int i=0;i<people.size();i++){
            int already_bloomed=upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int already_dead=lower_bound(end.begin(),end.end(),people[i])-end.begin();
            result.push_back(already_bloomed-already_dead);

        }
        return result;
    }
};