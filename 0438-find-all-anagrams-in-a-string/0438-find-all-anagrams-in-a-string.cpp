class Solution {
public:
    vector<int> findAnagrams(string txt, string pat) {
        vector<int> result;
        int n=txt.size();
        int m=pat.size();
        vector<int> v1 (26,0), v2(26,0);
        for(auto x: pat){
            v1[x-'a']++;
        }
        int i=0;
        for(int j=0;j<n;j++){
           v2[txt[j]-'a']++;
           if(j-i+1==m){
               if(v1==v2){
                   result.push_back(i);
               }
               v2[txt[i]-'a']--;
               i++;
           }
           
            
        }
        return result;
    }
};