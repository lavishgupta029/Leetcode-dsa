class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[count]=nums[i];
                count++;
            } 
           
        }
         for(int i=count;i<n;i++) nums[i]=0;
    }
};