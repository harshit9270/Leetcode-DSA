// Using priority queue
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i : nums)
            pq.push(i);
        
        int i = 0;
        while(! pq.empty()){
            nums[i ++] = pq.top();
            pq.pop();
        }
        
        return nums;
    }
};