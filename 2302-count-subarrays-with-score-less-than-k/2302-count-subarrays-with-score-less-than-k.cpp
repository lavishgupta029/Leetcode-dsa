class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result=0;
        int i=0,j=0,n=nums.size();
        long long currSum=0;
        while(j<n){
            currSum += nums[j];
            while(i<=j && currSum*(j-i+1)>=k){
                currSum -= nums[i];
                i++;
            }
            result += (j-i+1);
            j++;
        }
        return result;
    }
};