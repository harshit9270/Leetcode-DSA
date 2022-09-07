class Solution {
public:
    // Using binary search
    vector<int> twoSum(vector<int>& numbers, int target) {   
        
        for(int i=0; i<numbers.size()-1; i++){
            int start = i+1, end = numbers.size()-1;
            
            while(start <= end){
                int mid = start + (end-start)/2;
                
                if(numbers[i] + numbers[mid] == target)
                    return {i+1, mid+1};
                else if(numbers[i] + numbers[mid] < target)
                    start = mid+1;
                else
                    end = mid-1;
                
            }
        }
        
        return {0, 0};
    }
};