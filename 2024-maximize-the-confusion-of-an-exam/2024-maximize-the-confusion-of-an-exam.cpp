class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int K) {
        int result=0;
        int i=0,j=0,k=0,n=answerKey.size();
        int TCounter=0,FCounter=0;

        while(j<n){
            if(answerKey[j]=='T') TCounter ++;
            else FCounter ++;

            while(min(TCounter,FCounter)>K){
                if(answerKey[i]=='T') TCounter --;
                else FCounter--;
                i++;
            }
            // while(FCounter>K){
            //     if(answerKey[j]=='F') FCounter--;
            //     k++;
            // }
            result =max(result,j-i+1);
            j++;

        }
        return result;
    }
};