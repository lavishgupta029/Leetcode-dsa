class Solution {
public:
    vector<vector<int>> result;
    void helper(vector<int>& nums, vector<int>& temp, unordered_set<int> &st){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                helper(nums,temp,st);
                temp.pop_back();
                st.erase(nums[i]);
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> temp;
        helper(nums,temp,st);
        return result;
    }
};