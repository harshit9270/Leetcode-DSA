class Solution {
public:
    // Using binary search
    // Not optimal [O(n log n)]
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for(int i=0; i<arr.size(); i++){
            int low, high;
            if (arr[i] < 0){
				low = 0;
				high = i - 1;
			}
			else{
				low = i + 1;
				high = arr.size() - 1;
			}
            
            while(low <= high){
                int mid = low + (high-low)/2;
                
                if(arr[mid] == 2 * arr[i])
                    return true;
                else if(arr[mid] < 2 * arr[i])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        
        return false;
    }
};