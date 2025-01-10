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
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        vector<int> next(2,0);
        for(int i=n-1;i>=0;i--){
            vector<int> curr(2);
            for(int j=0;j<2;j++){
                int profit=0;
                if(j){
                    profit+= max( -prices[i]+next[0],next[1]);
                }
                else{
                    profit+= max( prices[i]+next[1],next[0]);
                }
                curr[j]=profit;
            }
            next=curr;
        }
        return next[1];
    }
};