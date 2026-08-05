class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(auto c : nums){
            nums[abs(c)-1] = -abs(nums[abs(c)-1]); 
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            {
                result.push_back(i+1);
            }
        }
        return result;
    }
};