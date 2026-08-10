class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int n=numbers.size();
        int i=0;
        int j=n-1;

        int sum = numbers[i]+numbers[j];
        while(i<j){
            if(sum==target){
                return {i+1, j+1};
            }
            else if(sum>target){
                sum -= numbers[j];
                j--;
                sum+= numbers[j];
            }
            else{
                sum -= numbers[i];
                i++;
                sum+= numbers[i];
            }
        }
        return {i+1, j+1};
    }
};