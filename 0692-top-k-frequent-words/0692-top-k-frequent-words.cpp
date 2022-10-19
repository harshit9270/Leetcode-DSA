// Using min heap
// Adding '-' sign to the value entered in priority queue makes it a min heap

class Solution {
	public:
		vector<string> topKFrequent(vector<string>& words, int k) {
			unordered_map <string, int> umap;
			for (string s: words) 
                umap[s]++;
			
            priority_queue <pair<int, string>> pq;
			
            for (auto it: umap) {
				// minus sign used to build min heap 
				pq.push({-it.second, it.first});
                
				if(pq.size() > k) 
                    pq.pop();
			}
			
            vector <string> res;
			while (k--) {
				res.insert(res.begin(), pq.top().second);
				pq.pop();
			}
			
            return res;
		}
	};