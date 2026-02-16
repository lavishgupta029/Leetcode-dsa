class Solution {
public:
    string removeDuplicates(string s) {
        string result="";
        stack<char> st;
        for(auto &ch: s){
            if(!st.empty() && ch == st.top()){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};