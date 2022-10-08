class MedianFinder {
private:
    priority_queue<int> maxpart;  // stores descending order of smaller ones     
    priority_queue<int, vector<int>, greater<int>> minpart;  // stores ascending order of larger ones
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {         
        maxpart.push(num);            
        minpart.push(maxpart.top());    
        maxpart.pop();                  
        
        // this step is to ensure if odd length is there, then maxPart->top stores the median to avoid any confusion
        if(maxpart.size() < minpart.size()){     
            maxpart.push(minpart.top());        
            minpart.pop();                     
        }
    }
    
    double findMedian() {
        if(maxpart.size() > minpart.size()) //odd length 
            return maxpart.top();   
        
        return (maxpart.top()+minpart.top())/2.0;    //even length
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */