class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n,-1);
        long long sum=0;
        int i=0,j=0;
        while(j<n){
            sum += nums[j];
            int range=2*k+1;
            if(j-i+1 == range){
                result[j-k]=sum/range;
                sum -=  nums[i];
                i++;
            }
            j++;
        }
        return result;
    }

};