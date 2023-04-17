class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        
        for(int i=0; i<candies.size(); i++){
            bool temp = true;
            for(int j=0; j<candies.size(); j++){
                if(candies[i] + extraCandies < candies[j]){
                   temp = false;   
                }
            }
            result.push_back(temp);
        }
        
        return result;
    }
};