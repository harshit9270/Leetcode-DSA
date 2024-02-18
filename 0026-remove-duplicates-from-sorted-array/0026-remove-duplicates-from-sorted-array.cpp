class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x = 1; // To check final length of the array
        
        // Iterate over the loop
        for(int i = 1 ;i < nums.size(); i++){
            // If previous number is equal to this number then the present number is repeated!!!
            if(nums[i] != nums[i-1]){
                // so we find all the number once (if they are repeating or not)
                // and store in the same array
                nums[x] = nums[i];
                x++;
            }
        }
        return x;
    }
};