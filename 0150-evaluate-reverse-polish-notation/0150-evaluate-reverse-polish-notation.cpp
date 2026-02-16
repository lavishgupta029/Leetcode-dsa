class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result=0;
        stack<int> st;
        for(auto &ch : tokens){

            if(ch=="+" || ch=="-" || ch=="*" || ch=="/"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                if(ch=="+") result= num1+num2;
                if(ch=="-") result= num1-num2;
                if(ch=="*") result= num1*num2;
                if(ch=="/") result= num1/num2;
                st.push(result);
            }
            else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};