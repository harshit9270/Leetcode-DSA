class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<bool> isPresent;
    
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; ++i)
            pq.push(i);
        
        isPresent = vector<bool>(1001,true);
    }
    
    int popSmallest() {
        int smallest_element = pq.top(); 
        pq.pop();
        
        isPresent[smallest_element] = false;
        
        return smallest_element;
    }
    
    void addBack(int num) {
        if(! isPresent[num]){
            pq.push(num);
            
            isPresent[num] = true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */