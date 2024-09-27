class Solution {
public:
int check(vector<int>& nums, int p,int n , int mid )
{
    int in  = 0;
    int cnt=0;
    for(int i =1; i<n;i++)
    {
        if(in)
        {
            in = 0;
            continue;
        }
        if(nums[i]-nums[i-1]<=mid)
        {
            in = 1;
            cnt++;
        }
    }
    return cnt>=p;
}

    int minimizeMax(vector<int>& nums, int p) {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        int low =0;
        int ans=INT_MAX;
        int high= nums[n-1]-nums[0];
        // int mid = low + (high-low)/2;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(nums,p, n, mid))
            {
                ans=mid;
                high= mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};