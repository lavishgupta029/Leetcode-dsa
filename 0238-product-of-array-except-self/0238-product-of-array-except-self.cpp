class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums),suf(nums),ans(size(nums));
        int n=nums.size();
        for(int i=1;i<n;i++){
            pre[i]=pre[i]*pre[i-1];
        }
        for(int j=n-2;j>=0;j--){
            suf[j]=suf[j]*suf[j+1];
        }

        for(int i=0;i<n;i++){
            ans[i]=(i ? pre[i-1]:1) * (i+1<n ? suf[i+1]:1);
        }
        return ans;
    }
};