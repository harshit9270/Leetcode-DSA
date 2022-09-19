// Precalculating left and right
class Solution {
public:
    // Each block can store a maximum of {min(leftMax, rightMax) - ownHeight}
    int trap(vector<int>& height) {
        int n = height.size();
        
        // left stores the maximum left element for every i th element
        // likewise right stores maximum element on right for every i th element
        vector<int> left(n), right(n);
        
        int water = 0;
        left[0] = height[0];
        
        for(int i=1; i<n; i++)
            left[i] = max(left[i-1], height[i]);
        
        right[n-1] = height[n-1];
        
        for(int i=n-2; i>=0; i--)
            right[i] = max(right[i+1], height[i]);
        
        for(int i=1; i<n-1; i++){
            int x = min(left[i], right[i]);
            
            if(x > height[i])
                water += x - height[i];
        }
        
        return water;        
    }
};