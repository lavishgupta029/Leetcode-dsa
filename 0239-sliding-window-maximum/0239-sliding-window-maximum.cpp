class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),i=0;
        vector<int> result;
        deque<int> dq;
        while(i<n){
            while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i>=k-1) result.push_back(nums[dq.front()]);
            i++;
        }
        return result;
    }
};