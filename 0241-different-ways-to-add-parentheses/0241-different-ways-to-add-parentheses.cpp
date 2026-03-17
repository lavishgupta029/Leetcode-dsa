class Solution {
public:

    vector<int> helper(string expression){
        vector<int> result;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='+'||expression[i]=='-' || expression[i]=='*'){
                vector<int> left_result=helper(expression.substr(0,i));
                vector<int> right_result=helper(expression.substr(i+1));

                for(auto &x : left_result){
                    for(auto &y: right_result){
                        if(expression[i]=='+'){
                            result.push_back(x+y);
                        }
                        else if(expression[i]=='-'){
                            result.push_back(x-y);
                        }
                        else{
                            result.push_back(x*y);
                        }
                    }
                }
            }
        }
        if(result.empty()){
            result.push_back(stoi(expression));
        }
        return result;
    }
    vector<int> diffWaysToCompute(string expression) {
        return helper(expression);
    }
};