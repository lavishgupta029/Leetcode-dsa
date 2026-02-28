class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int result =0;
        unordered_map<string,int> mp;
        for(auto &word:  words){
            string reverseWord= word;
            swap(reverseWord[0],reverseWord[1]);
            if(mp[reverseWord]>0){
                result += 4;
                mp[reverseWord]--;
            }
            else{
                mp[reverseWord]++;
            }
        }
        for(auto &word : mp){
            int count=mp[word];
            if(word[0]==word[1] && count >0  ){
                result += 2;
                break;
            }
        }
        return result;


    }
};