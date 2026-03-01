class Solution {
public:
    struct comp {
        bool operator()(pair<char,int> &a , pair<char,int> &b){
            return a.second<b.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<pair<char,int> ,vector<pair<char,int>> ,comp> pq;
        unordered_map<int,int> mp;
        for(auto &ch :s){
            mp[ch]++;
        }
        for(auto &ele : mp){
            pq.push({ele.first,ele.second});
        }
        string result="";

        while(!pq.empty()){
            pair<char,int> P=pq.top();
            pq.pop();
            result += string(P.second,P.first); 
        }
        return result;
    }
};