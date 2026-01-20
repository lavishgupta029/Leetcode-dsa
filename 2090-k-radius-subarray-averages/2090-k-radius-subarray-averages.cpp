class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> result(nums.size(),-1);
        if(k==0) return nums;
        int n=nums.size();
        if(2*k+1>n) return result ; 
        long long preCalc=0;
        for(int i=0;i<=2*k;i++){
            preCalc += nums[i];
        }
        cout<<preCalc<< "\n";
        for(int i=k;i<n-k;i++){
            if(i!=k){
                preCalc -= nums[i-k-1];
                preCalc += nums[i+k];
            }
            cout<<preCalc<< "\t";
            result[i]=preCalc/(2*k+1);
        }
        return result;


    }
};