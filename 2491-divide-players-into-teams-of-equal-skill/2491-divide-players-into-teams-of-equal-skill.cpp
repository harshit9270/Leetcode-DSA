class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long chemistry = 0;
        
        sort(skill.begin(), skill.end());
        int i=0, j=skill.size()-1;
        int sumOfSkill = skill[i] + skill[j];
        
        while(i < j){
            if(skill[i] + skill[j] != sumOfSkill)
                return -1;
            
            chemistry += skill[i] * skill[j];    
            i++;
            j--;
        }
        
        return chemistry;
    }
};