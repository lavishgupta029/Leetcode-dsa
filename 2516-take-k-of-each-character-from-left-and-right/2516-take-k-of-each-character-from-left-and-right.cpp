class Solution {
public:
    int takeCharacters(string s, int k) {
        int maxDeleteWindow=0;
        int i=0,j=0,n=s.size();
        vector<int> count(3,0);
        for(char &ch: s){
            cout<<ch-'a';
            count[ch-'a']++;
        }
        if(count[0]<k || count[1]<k || count[2]<k) return -1;

        while(j<n){
            count[s[j]-'a']--;
            while(i<=j && (count[0]<k || count[1]<k || count[2]<k)){
                count[s[i]-'a']++;
                i++;
            }
            maxDeleteWindow=max(maxDeleteWindow , j-i+1);
            j++;
        }
        return n-maxDeleteWindow;


    }
};