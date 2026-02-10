class Solution {
public:
    bool is_possible(vector<int>& dist, double hour, int mid){
        double currentHours=0.0;
        for(int i=0;i<dist.size()-1;i++){
            currentHours += ceil((double)dist[i]/(double) mid);
        }
        currentHours += (double)dist[dist.size()-1]/(double)mid;
        return currentHours<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low=1;
        int high=1e7;
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_possible(dist,hour,mid)){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return result;
    }
};