class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for(auto &pile: piles){
            pq.push(pile);
        }
        while(k>0){
            int top=pq.top();
            pq.pop();
            int floorValue=floor(top/2);
            pq.push(top-floorValue);
            k--;
        }
        int result=0;
        while(!pq.empty()){
            int top=pq.top();
            result+= top;
            pq.pop();
        }
        return result;
    }
};