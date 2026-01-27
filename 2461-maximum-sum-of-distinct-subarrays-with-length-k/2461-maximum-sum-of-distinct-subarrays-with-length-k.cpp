class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long result=0;
        long long currWindowSum=0;
        unordered_map<int,int> mp;
        int i=0,j=0,n=nums.size();
        while(j<n){
            currWindowSum += nums[j];
            mp[nums[j]]++;
            if(j-i+1==k){
                if(mp.size()==k){
                    result=max(result,currWindowSum);
                } 
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                currWindowSum -= nums[i];
                i++;
            }
            j++;
        }
        return result;
    }
};