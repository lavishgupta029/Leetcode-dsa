class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=target-nums[i];
            if(mp.find(num)!=mp.end()){
                ans.push_back(i);
                ans.push_back(mp[num]);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};