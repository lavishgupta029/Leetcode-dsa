class Solution {
public:
    string reverseParentheses(string s) {
        string result="";
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(result.length());
            }
            else if(s[i]==')'){
               int index=st.top();
               st.pop();
               reverse(result.begin()+ index ,result.end());
            }
            else{
                result += s[i];
            }
        }
        return result;
    }
};