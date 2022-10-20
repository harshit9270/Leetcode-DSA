class Solution {
private:
public:
    string intToRoman(int num) {
        string res = "";
        map<int,string> mp={{1,"I"},
                            {4,"IV"},
                            {5,"V"},
                            {9,"IX"},
                            {10,"X"},
                            {40,"XL"},
                            {50,"L"},
                            {90,"XC"},
                            {100,"C"},
                            {400,"CD"},
                            {500,"D"},
                            {900,"CM"},
                            {1000,"M"}};

        for(auto i=mp.rbegin(); i!=mp.rend(); i++){
            while(i->first <= num){
                num -= i->first;
                res += i->second;
            }
        }
        
        return res;
    }
};