// Using min heap and node

class node{
public:
    int data;
    int row, col;
    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<node*, vector<node*>, compare> pq;
        
        for(int i=0; i<k; i++){
            int element = nums[i][0];
            
            mini = min(mini, element);
            maxi = max(maxi, element);
            pq.push(new node(element, i, 0));
        }
        
        int start = mini, end = maxi;
        
        while(! pq.empty()){
            node* top = pq.top();
            pq.pop();
            
            mini = top->data;
            
            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }
            
            if(top->col+1 < nums[top->row].size()){ // since length of lists is variable
                maxi = max(maxi, nums[top->row][top->col+1]);
                
                pq.push(new node(nums[top->row][top->col+1], top->row, top->col+1));
            }
            else
                break;
        }
        
        return {start, end};
    }
};