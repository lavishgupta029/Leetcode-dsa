class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums,int idx){
        if(idx==nums.size()){
            result.push_back(nums);
            return;
        }

        for(int i=idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            helper(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return result;
    }
};