class Solution {
public:
    bool is_possible(vector<int>& position, int m, int force){
        int currM=1,prev=position[0];
        for(int i=1;i<position.size();i++){
            int curr=position[i];
            if(abs(curr-prev)>=force){
                currM++;
                prev=curr;
            }
            if(currM==m) break;
        }
        return currM==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int result=0;
        sort(position.begin(),position.end());
        int l=1;
        int r=*max_element(begin(position),end(position)) - *min_element(begin(position),end(position));

        while(l<=r){
            int mid=l+(r-l)/2;

            if(is_possible(position,m,mid)){
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