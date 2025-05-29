class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int n =heights.size();
        vector<int> left(n,0),right(n,0);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            int id=st.top();
            while(id!=-1 && heights[i]<=heights[id]){
                st.pop();
                id=st.top();
            }
            left[i]=id;
            st.push(i);
        }
        st=stack<int>();
        st.push(n);
        for(int i=n-1;i>=0;i--){
            int id=st.top();
            while(id!=n && heights[i]<=heights[id]){
                st.pop();
                id=st.top();
            }
            right[i]=id;
            st.push(i);
            ans =max(ans,(right[i]-left[i]-1)*heights[i]); 
        }
        return ans;
    }
};