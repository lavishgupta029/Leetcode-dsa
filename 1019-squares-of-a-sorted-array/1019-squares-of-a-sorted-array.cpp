class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        int start=0,end=n-1;
        while(start<=end){
            int num1=nums[start],num2=nums[end];
            if(abs(num1)<=abs(num2)){
                ans.push_back(num2*num2);
                end--;
            }
            else{
                ans.push_back(num1*num1);
                start++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};