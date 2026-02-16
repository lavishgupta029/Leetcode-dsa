class MyQueue {
public:
    stack<int> input, output;
    int peakEle=-1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peakEle=x;
        }
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            while(!input.empty()){
                int ele=input.top();
                output.push(ele);
                input.pop();
            }
        }
        int res=output.top();
        output.pop();
        return res;
    }
    
    int peek() {
        if(output.empty()){
            return peakEle;
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */