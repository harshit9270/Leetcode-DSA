class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
	unordered_map<int,int> mp;
	int ans = INT_MAX;
	
	for(int i=0; i<cards.size(); i++){
		int card = cards[i];
		// If card already already exists
		if(mp.find(card) != mp.end()){
			ans = min(ans, i-mp[card]+1);
		}
		// Update the index of the card
		mp[card] = i;
	}
        
	return ans == INT_MAX ? -1 : ans;
}
};