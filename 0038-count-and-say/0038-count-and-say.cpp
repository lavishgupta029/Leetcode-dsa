class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1) return s;
        for(int i=2;i<=n;i++){
            string temp="";
            char rep=s[0];
            int freq=1;
            int j=1;
            while(j<s.length()){
                if(rep!=s[j]){
                    temp+=to_string(freq)+rep;
                    rep=s[j];
                    freq=1;
                }
                else{
                    freq++;
                }
                j++;
            }
            temp+=to_string(freq)+rep;
            s=temp;
        }
        return s;
    }
};