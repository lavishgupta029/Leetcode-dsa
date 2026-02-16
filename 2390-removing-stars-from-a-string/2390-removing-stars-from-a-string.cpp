class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string result="";
        for(auto &ch: s){
            if(!st.empty()&& ch=='*' ) st.pop();
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