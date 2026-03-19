class Solution {
public:
    vector<int> result;
    void helper(int currNum, int n){
        if(currNum>n) return;
        result.push_back(currNum);

        for(int i=0;i<=9;i++){
            int newNum = (currNum*10)+i;
            
            if(newNum>n) return;
            helper(newNum,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        for(int i=1;i<=9;i++){
            helper(i,n);
        }
        return result;
    }
};