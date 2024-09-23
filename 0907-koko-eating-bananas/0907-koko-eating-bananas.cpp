class Solution {
public:
    bool is_possible(int k,vector<int>& piles, int h)
    {
        long long totalHour=0;
        for(auto i:piles){
            totalHour += ceil(i*1.0/k);
        }
        return (totalHour<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(auto x: piles){
            high += x;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(mid,piles,h)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};