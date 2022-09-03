class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len = arr2.size();
		int count = 0;
        sort(arr2.begin(), arr2.end());
        
        for(int i = 0; i < arr1.size(); i++) {
            bool flag = false;            
            int s = 0;
			int e = len - 1;
			int m;
            
            while(s <= e) {
                m = s + (e - s) / 2;
               if(abs(arr2[m] - arr1[i]) <= d) {
                    flag = true;
                    break;
               }
                
                else if(arr2[m] > arr1[i]) {
                    e = m - 1;
				}
                
                else {
                    s = m + 1;
				}
            }
            
            if(!flag) {
                count++;
			}
        }
        return count;
    }
};