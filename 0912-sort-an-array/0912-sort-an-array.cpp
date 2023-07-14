class Solution {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            if (arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (k = 0; k < temp.size(); ++k)
            arr[k + left] = temp[k];
    }
    
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSort(nums, left, right);
        return nums;
    }
};
