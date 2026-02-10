class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost , long long mid){
        long long currentCost=0;
        for(int i=0;i<nums.size();i++) {
            currentCost += abs(mid-nums[i])*cost[i];
        }
        return currentCost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low=*min_element(nums.begin(),nums.end());
        long long high=*max_element(nums.begin(),nums.end());
        long long result=0;

        while(low<=high){
            long long mid= low+(high-low)/2;
            long long cost1=findCost(nums,cost,mid);
            long long cost2=findCost(nums,cost,mid+1);
            result=min(cost1,cost2);
            if(cost1>cost2) low=mid+1;
            else high=mid-1;
        }
        return result;
    }
};