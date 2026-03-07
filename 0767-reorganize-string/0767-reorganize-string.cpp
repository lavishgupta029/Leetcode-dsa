class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        int n=s.size();
        string result(n,' ');
        for(auto &ch: s){
            mp[ch]++;
        }
        for(auto &ele: mp){
            pq.push({ele.second,ele.first});
        }
        if((n%2==0 && pq.top().first>n/2) || (n%2!=0 && pq.top().first>(n+1)/2) ){
            return "";
        }
        int i=0;
        while(!pq.empty()){
            int currFreq=pq.top().first;
            char ele=pq.top().second;
            pq.pop();
            while(currFreq>0){
                result[i]=ele;
                i=(i+2);
                if(i>=n) i=1;
                currFreq--;
            }
            // i=(i+2)%n;
        }
        return result;

    }
};