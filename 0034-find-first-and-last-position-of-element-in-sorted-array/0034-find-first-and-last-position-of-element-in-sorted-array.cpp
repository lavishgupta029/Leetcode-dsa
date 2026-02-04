class Solution {
public:

    int leftMostElement(int n,vector<int>& nums, int target ){
        int l=0,r=n-1;
        int left_most=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target) r=mid-1;
            else if (nums[mid]<target) l=mid+1;
            else{
                left_most=mid;
                r=mid-1;
            }
        }
        return left_most;
    }

    int rightMostElement(int n,vector<int>& nums, int target ){
        int l=0,r=n-1;
        int right_most=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]>target) r=mid-1;
            else if (nums[mid]<target) l=mid+1;
            else{
                right_most=mid;
                l=mid+1;
            }
        }
        return right_most;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int left_most=leftMostElement(n,nums,target);
        int right_most=rightMostElement(n,nums,target);
        return {left_most,right_most};
    }
};