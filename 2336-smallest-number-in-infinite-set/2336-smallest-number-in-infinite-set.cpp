class SmallestInfiniteSet {
public:
    int i;
    set<int> st;
    SmallestInfiniteSet() {
        i=1;
    }
    
    int popSmallest() {
        if(st.size()>0){
            int firstEle= *st.begin();
            st.erase(firstEle);
            return firstEle;
        }
        else{
            i++;
            return i-1;
        }
        return 0;
    }
    
    void addBack(int num) {
        if(i>num){
            st.insert(num);
        }
        

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */