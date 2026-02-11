class Solution {
public:
    bool is_possible(vector<int>& nums, int p, int mid){
        int pairs=0;
        for(int i=0;i< nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                pairs++;
                i++;
            }
        }
        return pairs>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=nums[n-1]-nums[0];
        int result;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(is_possible(nums,p,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;

    }
};