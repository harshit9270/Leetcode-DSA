class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int h = num.size() - 1;
        
        while(l < h) {
            int mid = l + (h - l) / 2;
            
            if (num[mid] > num[h]) 
                l = mid + 1;
            else if (num[mid] < num[h])
                h = mid;
            else // when num[mid] and num[hi] are same
                h--;
        }
        return num[l];
    }
};