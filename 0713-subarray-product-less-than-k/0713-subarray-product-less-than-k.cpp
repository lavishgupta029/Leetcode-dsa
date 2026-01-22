class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result=0;
        long long product=1;
        int i=0,j=0,n=nums.size();
        if(k<=1) return 0;
        while(j<n){
            product = product * nums[j];
            while(k<=product){
                product /= nums[i];
                i++;
            }
            result += j-i+1;
            j++;
        }
        return result;

    }
};