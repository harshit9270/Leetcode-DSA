// Using binary search

class Solution {
public:
    int hIndex(vector<int>& c) {
        int start = 0, end = c.size() - 1, mid;
        
        sort(c.begin(), c.end());
        
        while (start <= end) {
            mid = (start + end)/2;
            
            if(c[mid] == c.size()-mid)
                return c[mid];
            else if(c[mid] > c.size()-mid)
                end = mid-1;
            else
                start = mid+1;
        }
        
        //if we did not find c[mid] == c.size()-mid we return all elements righthand side
        return c.size() - start;
    }
};