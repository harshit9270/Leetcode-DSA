class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0), result;
        int c = 0;

        for (auto query : queries) {
            int index = query[0], color = query[1];
            int pre = (index > 0) ? nums[index - 1] : 0;
            int nex = (index < n-1) ? nums[index + 1] : 0;

            if (nums[index] && nums[index] == pre) c--;
            if (nums[index] && nums[index] == nex) c--;
            nums[index] = color;
            if (nums[index] == pre) c++;
            if (nums[index] == nex) c++;

            result.push_back(c);
        }
        return result;
    }
};