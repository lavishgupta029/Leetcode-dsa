class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int culpIndex=-1,minKPosition=-1,maxKPosition=-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==minK) minKPosition=i;
            if(nums[i]==maxK) maxKPosition=i;
            if(nums[i]<minK || nums[i]>maxK) culpIndex=i;
            int smaller=min(minKPosition,maxKPosition);
            int temp= smaller-culpIndex;
            ans+= temp>0?temp:0;
        }
        return ans;
    }
};