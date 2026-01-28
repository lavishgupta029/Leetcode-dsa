class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long result=0;
        multiset<int> st;
        int i=0,j=0,n=nums.size();
        while(j<n){
            st.insert(nums[j]);
            while(i<j && *prev(st.end())-*st.begin()>2){
                auto it=st.find(nums[i]);
                st.erase(it);
                i++;
            }
            result  +=  j-i+1;
            j++;
        }
        return result;
    }
};