class Solution {
public:
    bool is_possible(vector<int>& bloomDay, int m, int k, int mid){
        int currM=0;
        int pick=0;
        for(int i=0;i<bloomDay.size();i++){
            
            if(bloomDay[i]<=mid){
                pick++;
            }else{
                pick=0;
            }
            if(pick==k) {
                currM++;
                pick=0;
            }
        }
        return currM>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int result=0;
        int l=1;
        int r=*max_element(begin(bloomDay),end(bloomDay));
        if((long long)m*k>(long long)bloomDay.size()) return -1;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(is_possible(bloomDay,m,k,mid)){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return result;
    }
};