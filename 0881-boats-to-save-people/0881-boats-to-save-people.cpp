class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int i=0, j=people.size()-1, count = 0;
        
        while(i <= j){
            if(people[i] + people[j] <= limit){
              // when sum is less or atmost equivalent to given limit;
                i++;
                j--;
            }
            else
                // if the sum comes greater than limit than push the heavier weight person to go alone in the boat.
                j--;
            
            count ++;
        }
        
        return count;
    }
};