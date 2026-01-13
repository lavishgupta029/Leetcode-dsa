class Solution {
public:
    string reverseWords(string s) {
        string reverseSentence="";
        string word="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                word += s[i];
            }
            else{
                if(word.size()!=0){
                    st.push(word);
                    word="";
                }
            }
        }
        if(word.size()!=0){
            st.push(word);
            word="";
        }
        while(!st.empty()){
            if(st.size()==1){
                reverseSentence += st.top();
                st.pop();
                continue;
            }
            reverseSentence += st.top();
            reverseSentence += ' ';
            st.pop();
        }
        return reverseSentence;
    }
};