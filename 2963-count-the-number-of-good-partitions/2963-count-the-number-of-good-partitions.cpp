class Solution {
public:
    int M=1e9+7;
    int numberOfGoodPartitions(vector<int>& nums) {
        int ans=1;
        
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }

        int i=0;
        int j=mp[nums[0]];
        int n=nums.size();
        while(i<n){
            if(i>j){
                ans = (ans*2) % M;
            }
            j=max(j,mp[nums[i]]);
            i++;
        }
        return ans;
    }
};