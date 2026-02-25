class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st;
        string result="";
        for(auto &word: dictionary) {
            st.insert(word);
        }
        int i=0;
        int n=sentence.size();
        while(i<n){
            string curr="";
            int flag=0;
            while(i<n && sentence[i]!=' '){
                curr += sentence[i];
                if(st.count(curr) && flag==0){
                    result += curr;
                    result += ' '; 
                    flag=1;                   
                }
                i++;
            }
            if(flag==0){
                result += curr;
                result += ' ';
            }
            i++;
        }
        result.pop_back();
        return result;
    }
};