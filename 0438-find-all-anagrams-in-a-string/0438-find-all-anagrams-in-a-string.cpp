class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> count(26,0);
        for(char &ch : p) count[ch-'a']++;
        int i=0,j=0;
        int n=p.size(),m=s.size();
        while(j<m){
            count[s[j]-'a']--;
            if(j-i+1==n){
                if(count==vector<int>(26,0)) result.push_back(i);
                count[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return result;
    }
};