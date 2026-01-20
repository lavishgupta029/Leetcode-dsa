class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_set<int> st;
        int i=0,j=0;
        int n=nums.size();
        while(i<n){
            auto it = st.find(nums[i]);
            if(it!=st.end()) return true;
            st.insert(nums[i]);
            if(i-j==k){
                st.erase(nums[j]);
                j++;
            }
            i++;
        }
        return false;
    }
};