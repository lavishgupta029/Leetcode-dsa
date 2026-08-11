class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT_MAX;
        int n=nums.size();
        int currSum=0;
        int j=0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            
            while(currSum>=target){
                currSum -= nums[j];
                result = min(result,i-j+1);
                j++;
            }
            
        }
        return result==INT_MAX?0:result;
    }
};