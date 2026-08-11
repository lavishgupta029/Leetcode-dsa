class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> indexVal(256,-1);
        int i=0;
        int n=s.size();
        int result=0;
        for(int j=0;j<n;j++){
            if(indexVal[s[j]] !=-1){
                i=max(indexVal[s[j]]+1,i);
            }
            indexVal[s[j]]= j;
            result = max(result, j-i+1);
        }
        return result;
    }
};