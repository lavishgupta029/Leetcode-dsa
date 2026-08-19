class Solution {
public:
    int M=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        vector<int> mp(26,0);

        for(char &ch: s){
            mp[ch-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<int> temp(26,0);
            for(int j=0;j<26;j++){
                char ch=j+'a';
                int freq = mp[j];
                if(ch!='z'){
                    temp[ch+1-'a']=(temp[ch+1-'a']+freq)%M;
                }
                else{
                    temp['a'-'a']=(temp['a'-'a']+freq)%M;
                    temp['b'-'a']=(temp['b'-'a']+freq)%M;
                }
            }
            mp=temp;
        }
        int count=0;
        for(int i=0;i<26;i++){
            count = (count+ mp[i])%M;
        }
        return count;
    }
};