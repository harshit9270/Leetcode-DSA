class Solution {
public:        
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        int MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        
        // for every i find the Next smaller element to left and right
        // Left
        stack<int>st;
        st.push(0);
        left[0] = 1; 
        for(int i=1; i<n; i++)
        {
            while(!st.empty() && A[i] < A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                left[i] = i+1; 
            else 
                left[i] = i - st.top(); 
            
            st.push(i);
            
        }
        
        while(st.size()) 
            st.pop();
        
        // Right 
        st.push(n-1);
        right[n-1] = 1; 
        for(int i=n-2; i>=0; i--)
        {
            while(!st.empty() && A[i] <= A[st.top()]) 
                st.pop();
            
            if(st.empty()) 
                right[i] = n-i; 
            else 
                right[i] = st.top()-i;
            
            st.push(i);
        }
        
        // total number of subarrays : (Left[i] * Right[i])
        // total contribution in A[i] element in final answer : (Left * Right) * A[i] 
        
        for(int i=0; i<n; i++) 
             cout << left[i] << " : " << right[i] << endl;
        
        // for each i, contribution is (Left * Right) * Element 
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*A[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
    
};