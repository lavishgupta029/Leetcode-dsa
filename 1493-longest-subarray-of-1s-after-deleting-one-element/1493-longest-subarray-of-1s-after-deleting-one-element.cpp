class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int countZero=0;
        int result=0;
        int n=nums.size();
        int i=0,j=0;

        while(j<n){
            if(nums[j]==0) countZero++;
            while(countZero>1){
                if(nums[i]==0 ) countZero--;
                i++;
            }
            result=max(result,j-i);
            j++;
        }
        return result;
    }
};