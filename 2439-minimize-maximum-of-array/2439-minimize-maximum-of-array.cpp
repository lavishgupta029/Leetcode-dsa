class Solution {
public:

    bool is_valid(vector<int>& nums,int expectedAnswer ){

        vector<long long> arr(begin(nums), end(nums));

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>expectedAnswer) return false;
            long long buffer=expectedAnswer-arr[i];
            arr[i+1]=arr[i+1]-buffer;
        }
        return arr[arr.size()-1]<=expectedAnswer;
    }
    int minimizeArrayValue(vector<int>& nums) {
        
        int n=nums.size();
        int low=0;
        int high=*max_element(nums.begin(),nums.end());
        int result;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(is_valid(nums,mid)){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result; 
    }
};