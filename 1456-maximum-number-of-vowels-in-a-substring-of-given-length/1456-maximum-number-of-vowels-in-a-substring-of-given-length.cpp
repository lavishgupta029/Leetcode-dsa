class Solution {
public:
    int maxVowels(string s, int k) {
        int result=0;
        int vowelCount=0;
        int i=0,j=0,n=s.size();
        unordered_set<char> st={'a','e','i','o','u'};
        while(j<n){
            if(st.find(s[j])!=st.end()){
                vowelCount++;
            }
            if(j-i+1==k){
                result=max(result,vowelCount);
                if(st.find(s[i])!=st.end()){
                    vowelCount--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};