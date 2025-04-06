class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++){
            ans+=cardPoints[i];
        }
        if(k>=n) return ans;
        int j=n-1;
        int newAns=ans;
        for(int i=k-1;i>=0;i--){
            newAns -= cardPoints[i];
            newAns += cardPoints[j];
            ans=max(ans,newAns);
            j--;
        }
        return ans;
    }
};