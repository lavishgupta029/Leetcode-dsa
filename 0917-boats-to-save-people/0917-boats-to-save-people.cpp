class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans=0;
        sort(people.begin(),people.end());
        int n=people.size();
        int i=0,j=n-1;
        while(i<=j){
            if(people[i]+people[j]>limit){
                j--;
            }
            else{
                i++;
                j--;
            }
            ans++;
        }
        return ans;
    }
};