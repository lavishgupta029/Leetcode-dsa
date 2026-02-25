class Solution {
public:
    int minimumPushes(string word) {
        unordered_set<char> st;
        for(auto &ch: word){
            st.insert(ch);
        }
        if(st.size()>=1 && st.size()<=8) return st.size();
        else if (st.size()>8 && st.size()<=16) return 8+ 2*(st.size()-8);
        else if (st.size()>16 && st.size()<=24) return 8+ 2*8 +3*(st.size()-16);
        else return 8+ 2*8 +3*8 + 4*(st.size()-24);

    }
};