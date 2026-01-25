class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int result=0;
        int n=customers.size();
        int currCust=0,maxCust=0;
        // int max_i,max_j;
        int i=0,j=0;
        while(j<n){
            if(grumpy[j]==1) currCust += customers[j];
            if(j-i+1==minutes){
                if(currCust>maxCust){
                    maxCust=currCust;
                }
                if(grumpy[i]==1) currCust -= customers[i];
                i++;
            }
            j++;
        }
        result = maxCust;
        // cout<<max_i<<max_j;
        for(i=0;i<n;i++){
            if(grumpy[i]==0) {
                result += customers[i];
            }
                
        }
        return result;

    }
};