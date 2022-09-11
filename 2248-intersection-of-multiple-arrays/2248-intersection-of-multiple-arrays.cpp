class Solution {
public:
     vector<int> intersection(vector<vector<int>>&nums) {
        map<int, int> countMap;
        vector<int> inEachArray;
         
        for (auto num : nums) {
            for (auto x : num) {
                countMap[x]++;
                if (countMap[x] == nums.size())
                     inEachArray.push_back(x);
            }
        }
         
        sort(inEachArray.begin(), inEachArray.end());
        return inEachArray;
    }
};