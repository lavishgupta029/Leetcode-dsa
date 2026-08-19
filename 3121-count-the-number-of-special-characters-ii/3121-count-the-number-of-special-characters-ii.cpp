class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> smallLet(26,-1);
        vector<int> largeLet(26,-1);
        int n=word.size();
        int result=0;
        for(int i=0;i<n;i++){
            if(word[i]>= 'a' && word[i]<='z' ){
                smallLet[word[i]-'a']=i;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(word[i]>= 'A' && word[i]<='Z' ){
                largeLet[word[i]-'A']=i;
            }
        }
        for(int i=0;i<26;i++){
            if(smallLet[i]!=-1 && largeLet[i]!=-1 && smallLet[i]<largeLet[i]) result++;
        }


        return result;
    }
};