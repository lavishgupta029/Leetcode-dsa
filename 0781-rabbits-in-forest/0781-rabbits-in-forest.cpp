class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int result=0;
        unordered_map<int,int> mp;

        for(auto &answer: answers){
            mp[answer]++;
        }
        for (auto &ele : mp){
            int color=ele.first;
            int colorCount=ele.second;
            int groupSize= color+1;

            int group = ceil((double)colorCount/groupSize );

            result += group * groupSize;
        }
        return result;
    }
};