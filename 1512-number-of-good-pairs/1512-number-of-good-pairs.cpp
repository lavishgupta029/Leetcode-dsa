class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result=0;
        map<int,int> mp;
        for(auto &num: nums){
            mp[num]++;
        }
        for(auto &it: mp){
            result +=( it.second*(it.second-1) )/ 2;
        }
        return result;
    }
};