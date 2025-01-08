class Solution {
public:
    int jump(vector<int>& nums) {
        int currReach=0;
        int maxReach=0;
        int jumps=0;

        for(int i=0;i<nums.size()-1;i++){
            if(maxReach<nums[i]+i){
                maxReach=nums[i]+i;
            }

            if(currReach==i){
                jumps++;
                currReach=maxReach;
            }
        }
        return jumps;
    }
};