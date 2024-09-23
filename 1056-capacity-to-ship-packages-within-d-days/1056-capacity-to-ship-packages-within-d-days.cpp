class Solution {
public:
    bool is_possible(int mid,vector<int> &weights,int days){
        int countDays=0;
        int w=0;
        for(auto x: weights){
            if(w+x>mid){
                w=x;
                countDays++;
            }
            else{
                w=w+x;
            }
        }
        countDays++;
        return countDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(mid,weights,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};