class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m; 
    TimeMap() {
        
    }
    
    string greatestValLessThan(int timestamp, vector<pair<int, string>>& s){
        int start = 0, end = s.size()-1;
        int ans = INT_MIN;
        string str = "";
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            auto x = s[mid];
            int num = x.first;
            string str_temp = x.second;
            
            if(num > timestamp){
                end = mid -1;
            }
            else{
                if(num > ans){
                    str = str_temp;
                    ans = num;
                }
                start = mid+1;
            }
        }
        
        return str;
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});  
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        
        ans = greatestValLessThan(timestamp,m[key]);
        return ans;
    }
    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */