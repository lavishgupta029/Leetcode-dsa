class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=INT_MAX;
        int diff=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int num1=nums[i];
            int start=i+1;
            int end=n-1;
            while(start<end){
                int num2=nums[start];
                int num3=nums[end];
                int sum=num1+num2+num3;
                int currDiff=abs(target - sum);
                if(currDiff==0) return sum;
                if(currDiff<diff){
                    ans=sum;
                    diff=currDiff;
                }
                if(sum<target) start++;
                else end--;
                // while(start<end &&nums[start]==num2) start++;
                // while(start<end &&nums[end]==num3) end--;
            }
        }
        return ans;
    }
};