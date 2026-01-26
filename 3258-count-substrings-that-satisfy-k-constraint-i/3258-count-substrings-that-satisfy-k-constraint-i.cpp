class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int result=0;
        int zero=0,one=0;
        int i=0,j=0,n=s.size();

        while(j<n){
            if(s[j]=='0') zero++;
            else one++;
            while(zero>k && one>k){
                if(s[i]=='0') zero--;
                else one--;
                i++;
            }
            result += j-i+1;
            j++;
        }
        return result;
    }
};