class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> result;
        int n=spells.size();
        int m=potions.size();
        for(int i=0;i<n;i++){
            int left=0;
            int right=m-1;
            if((long long)spells[i]*potions[m-1]<success) {
                result.push_back(0);
                continue;
            }
            while(left<right){
                int mid=left+(right-left)/2;
                long long spellStrength= (long long)potions[mid]*spells[i];
                if(spellStrength >=success ) {
                    right=mid;
                }
                else left=mid+1;
                
            }
            result.push_back(m-left);
        }
        return result;

    }
};