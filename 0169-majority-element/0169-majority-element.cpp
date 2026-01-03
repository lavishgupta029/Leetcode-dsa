class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int currEle=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(currEle==nums[i]) count ++;
            else count--;
            if(count==0){
                currEle=nums[i];
                count=1;
            }
        }
        return currEle;
    }
};