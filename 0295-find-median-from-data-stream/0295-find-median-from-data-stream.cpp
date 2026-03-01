class MedianFinder {
public:
    priority_queue<int> maxEle;
    priority_queue<int,vector<int>, greater<int>> minEle;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxEle.push(num);
        minEle.push(maxEle.top());
        maxEle.pop();
        if(minEle.size()>maxEle.size()){
            int ele=minEle.top();
            minEle.pop();
            maxEle.push(ele);
        }
    }
    
    double findMedian() {
        if(maxEle.size()>minEle.size()){
            return maxEle.top();
        }
        else{
            return (double)( maxEle.top()+minEle.top() ) /2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */