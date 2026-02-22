class Solution {
public:
    int minSwaps(string s) {
        int result=0;
        stack<char> st;
        for(auto &str: s){
            if(str=='['){
                st.push(str);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        // cout<<st.size();
        return (st.size()+1)/2;
    }
};