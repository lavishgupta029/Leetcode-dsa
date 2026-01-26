class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        for(char &ch : s1){
            count[ch-'a']++;
        }
        int i=0,j=0,n=s2.size();
        while(j<n){
            count[s2[j]-'a']--;
            if(j-i+1==s1.size()){
                if(count==vector<int>(26,0)) return true;
                count[s2[i]-'a']++;
                i++;
            }
            j++;
        }
        return false;
        
    }
};