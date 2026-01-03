class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector Products(nums);
        int prefixProduct=1;
        for(int i=0;i<n;i++){
            Products[i] = prefixProduct;
            prefixProduct *= nums[i];
        }
        int suffixProduct=1;
        for(int i=n-1;i>=0;i--){
            Products[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }
        return Products;
    }
};