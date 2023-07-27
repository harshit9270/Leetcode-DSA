// Using stack
// Area of largest rectangle in histogram

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> s;
        vector<int> ans(n);
        
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(!s.empty() && arr[s.top()]>=curr)
                s.pop();
            
            //ans is stack ka top
            if(!s.empty())
                ans[i] = s.top()-1; 
            else
                ans[i] = n-1; 
            s.push(i);            
        }
        
        return ans;
    }
    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> s;
        vector<int> ans(n);
        
        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(!s.empty() && arr[s.top()]>=curr)
                s.pop();
            
            //ans is stack ka top
            if(!s.empty())
                ans[i] = s.top()+1; 
            else
                ans[i] = 0; 
            
            s.push(i);            
        }
        
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int vol = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l=heights[i];
            
            int b = next[i] - prev[i] + 1;
            int newVol = l*b;
            
            vol = max(vol, newVol);
        }
        
        return vol;
    }
};