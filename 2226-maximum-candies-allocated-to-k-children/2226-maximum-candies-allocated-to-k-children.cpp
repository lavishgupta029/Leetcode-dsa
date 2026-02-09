class Solution {
public:
    bool is_possible (  long long candy, vector<int>& candies, long long k ){
        long long currentChildrens=0;

        for(int i=0;i<candies.size();i++){
            currentChildrens += candies[i]/candy;
        }
        return currentChildrens>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low=1;
        int high=*max_element(candies.begin(),candies.end());
        int result=0;
        while(low<=high){
            long long mid=low +(high-low)/2;
            if(is_possible(mid, candies , k)){
                result=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return result;
    }
};