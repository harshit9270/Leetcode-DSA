class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        string res = "";
        vector<string> strNums(size, "");
        for (int i = 0; i < size; i++) {
            strNums[i] = to_string(nums[i]);
        }
        
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b){
            return ((a+b) > (b+a));
        });
        
        for (auto num : strNums) {
            res += num;
        }
        
        // if there are leading zeroes in res, then there is no chance for it to have a non-zero value i.e. it can be like '000', '0000', '00000'
        return res[0] == '0' ? "0" : res;
    }
};