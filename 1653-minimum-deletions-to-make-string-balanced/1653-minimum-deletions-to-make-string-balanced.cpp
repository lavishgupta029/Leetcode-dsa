class Solution {
public:
    int minimumDeletions(string s) {
        int result=0;
        stack<char> st;
        for(auto &str: s){
            if(!st.empty() && st.top()=='b' && str=='a'){
                st.pop();
                result++;
            }
            else{
                st.push(str);
            }
            
        }
        return result;
    }
};