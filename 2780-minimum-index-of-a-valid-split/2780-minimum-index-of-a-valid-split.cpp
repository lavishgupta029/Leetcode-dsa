class Solution {
public:
    int findMaxOcc(vector<int>& nums){
        int curr=-1;
        int currCount=0;
        for(int i=0;i<nums.size();i++){
            if(currCount==0){
                curr=nums[i];
                currCount=1;
            }
            else{
                if(nums[i]==curr){
                    currCount++;
                }
                else{
                    currCount--;
                }
            }
           
        }
        return curr;
    }
    int minimumIndex(vector<int>& nums) {
        int maxEle=findMaxOcc(nums);
        int countMaxEle=0;
        for(auto &num: nums){
            if(num==maxEle) countMaxEle++;
        }
        int leftCountMax=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxEle)leftCountMax++;
            int rightCountMax=countMaxEle-leftCountMax;
            int leftSize=i+1;
            int rightSize=n-i-1;
            if(leftCountMax*2>leftSize &&  rightCountMax*2>rightSize ) return i;

        }
        return -1;


    }
};