class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> picked;
        
        int max_fruits = 0;
        int start = 0, end = 0;
        
        while(end < fruits.size()){
            picked[fruits[end]] ++;
            
            while(picked.size() > 2)
            {
                if(picked[fruits[start]] == 1)
                    picked.erase(fruits[start]);
                else
                    picked[fruits[start]]--;
                
                start++;
            }
            
            max_fruits = max(max_fruits, end-start+1);
            
            end++;
        }
        
        return max_fruits;
    }
};