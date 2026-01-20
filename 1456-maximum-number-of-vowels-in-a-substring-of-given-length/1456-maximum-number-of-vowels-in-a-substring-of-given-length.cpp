class Solution {
public:
    int maxVowels(string s, int k) {
        int result=0,counter=0;
        unordered_set<char> st={'a','e','i','o','u'};
        int i=0,j=0,n=s.size();
        while(j<n){
            if(st.find(s[j])!=st.end()){
                counter++;
            }
            if(j-i+1==k){
                result=max(result,counter);
                if(st.find(s[i])!=st.end()){
                    counter--;
                }
                i++;
            }
            j++;
        }
        return result;

    }
};