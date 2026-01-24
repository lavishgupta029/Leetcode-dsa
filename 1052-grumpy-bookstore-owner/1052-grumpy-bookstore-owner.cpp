class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int initialSatisfy=0;
        int initialMax=0;
        int maxExtraSatisfaction =0;
        int n=customers.size();
        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                initialSatisfy += customers[i];
            }
            else if(i<minutes){
                initialMax+= customers[i];
            }
        }
            maxExtraSatisfaction=initialMax;
        for(int i=minutes;i<n;i++){
            initialMax -= customers[i-minutes]*grumpy[i-minutes];
            initialMax +=customers[i]*grumpy[i];
            maxExtraSatisfaction=max(initialMax,maxExtraSatisfaction);
        }
        return maxExtraSatisfaction+initialSatisfy;
    }
};