class Solution {
public:
    int helper(int i,int buy,int n, vector<vector<int>> &dp, vector<int>& p){
        
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit+= max( -p[i]+helper(i+1,0,n,dp,p),helper(i+1,1,n,dp,p));
        }
        else{
            profit+= max( p[i]+helper(i+1,1,n,dp,p),helper(i+1,0,n,dp,p));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,n,dp,prices);
    }
};