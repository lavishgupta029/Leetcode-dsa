class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result=0;
        unordered_set<int> st;
        int i=0,j=0,n=nums.size();
        int currSum=0;
        while(j<n)
        {
            while(st.find(nums[j])!=st.end()){
                currSum -= nums[i];
                st.erase(nums[i]);
                i++;
            }
            currSum += nums[j];
            st.insert(nums[j]);
            result=max(currSum,result);
            j++;
        }
        return result;
    }
};