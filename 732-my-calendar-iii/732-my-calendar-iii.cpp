class MyCalendarThree {
public:
    map<int, int> mp;
    
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        // This somehow works, the sum of these values return number of overlapping intervals
        // I could not figure out why :)
        mp[start]++;        
        mp[end]--;
        
        // iterate over map and find the maximum overlapping bookings
        int maxi = INT_MIN;
        int sum = 0;
        
        for(auto x : mp){
            sum += x.second;
            
            maxi = max(maxi, sum);
        }
        
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */