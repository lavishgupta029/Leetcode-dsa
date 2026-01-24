class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result=0;
        int n=s.size();
        int i=0,j=0;
        int currCost=0;
        while(j<n){
            currCost += abs((s[j]-'a') - (t[j] - 'a'));
            while(currCost>maxCost){
                currCost -= abs((s[i]-'a') - (t[i] - 'a'));
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;

    }
};