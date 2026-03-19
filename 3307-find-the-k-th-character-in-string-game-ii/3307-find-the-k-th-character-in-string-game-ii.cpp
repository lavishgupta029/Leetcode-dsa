class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return 'a';

        long long len=1;
        int currOp=0;
        for(int i=0;i<operations.size();i++){
            len *=2;
            if(len>=k){
                currOp=operations[i];
                break;
            }
        }
        char ch= kthCharacter(k-len/2, operations);
        if(currOp==0) return ch;
        return ch=='z'? 'a' : ch+1;
    }
};