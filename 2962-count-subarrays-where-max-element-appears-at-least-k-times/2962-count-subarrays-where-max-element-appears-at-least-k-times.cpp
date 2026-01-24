class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result=0;
        int maxEleCount=0;
        int maxEle= *max_element(nums.begin(),nums.end());
        int i=0,j=0,n=nums.size();
        while(j<n){
            if(nums[j]==maxEle) maxEleCount++;
            while(maxEleCount>=k){
                result += n-j;
                if(nums[i]==maxEle) maxEleCount--;
                i++;
            }
            j++;
        }
        return result;
    }
};