#include <algorithm> 

class Solution {
public:
    long long mod= 1e9+7;
    long long dp[200][201][201];
    long long helper(long long i,long long ga,long long gb, vector<int>& nums){
        if(i==nums.size()){
            if(ga==gb && ga!=0) return 1;
            return 0;
        }
        if(dp[i][ga][gb]!=-1) return dp[i][ga][gb];
        long long ans=helper(i+1,ga,gb,nums);
        if(ga==0){
            ans += helper(i+1,nums[i],gb,nums);
        }
        else{
            ans += helper(i+1,gcd(ga,nums[i]),gb,nums);
        }
        if(gb==0){
            ans += helper(i+1,ga,nums[i],nums);
        }
        else{
            ans += helper(i+1,ga,gcd(gb,nums[i]),nums);
        }

        return dp[i][ga][gb]=ans%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,0,nums);

    }
};