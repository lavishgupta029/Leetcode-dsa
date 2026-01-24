class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int,int> mp;
        int i=0,j=0,big_i=0,n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                big_i=i;
            }

            while(mp[nums[i]]>1){
                mp[nums[i]]--;
                i++;
            }
            if(mp.size()==k) result += 1+(i-big_i);
            j++;
        }
        return result;
    }
};