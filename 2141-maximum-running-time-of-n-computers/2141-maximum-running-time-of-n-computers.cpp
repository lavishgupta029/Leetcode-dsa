class Solution {
public:
    typedef long long ll;
    bool is_possible(int n, vector<int>& batteries , ll mid){
        ll target = mid*n;
        for(int i=0;i<batteries.size();i++){
            target -= min((ll)batteries[i],mid  );

            if(target<=0) return true;
        }
        return target<=0;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        ll l=*min_element(batteries.begin(), batteries.end());
        ll result=0;
        ll sum=0;
        for(auto &battery: batteries) sum += battery;
        ll r=sum/n;
        while(l<=r){
            ll mid= l+(r-l)/2;
            if(is_possible(n, batteries, mid)){
                result=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return result;
    }
};