// Using stack (Yet to understand this approach)
class Solution {
public:
    // Each block can store a maximum of {min(leftMax, rightMax) - ownHeight}
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int water = 0;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && height[st.top()] < height[i]){
                int pop_height = height[st.top()];
                st.pop();
                
                if(st.empty())
                    break;
                
                int distance = i-st.top()-1;
                
                int min_height = min(height[st.top()], height[i]) - pop_height;
                
                water += distance*min_height;
            }
            
            st.push(i);
        }
        
        return water;
    }
};