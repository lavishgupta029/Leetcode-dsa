class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> result(n,0);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            
            while( !st.empty() && temperatures[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()) {
                st.push({temperatures[i],i});
                result[i]=0;
                continue;
            }
            result[i] = st.top().second - i;
            st.push({temperatures[i],i});
        }
        return result;
        
    }
};