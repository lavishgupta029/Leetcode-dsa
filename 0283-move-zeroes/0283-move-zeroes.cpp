class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0, i=0;
        int len=nums.size();

        while(j<len){
            if(nums[j]==0) j++;
            else{
                swap(nums[i],nums[j]);
                j++;
                i++;
                
            }
        }
    }
};