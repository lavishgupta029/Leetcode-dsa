class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;   
        stack<string> st;
        string result="";
        while(getline(ss,token,'/')){
            if(token == "" ||  token == ".") continue;
            else if(token != ".." ){
                
                st.push(token);
            }
            else if(!st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            result = '/' + st.top()+result;
            st.pop();
        }
        if(result == "") return "/";
        // reverse(begin(result),end(result));
        return result;
    }
};