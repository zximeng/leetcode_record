class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        // this question is just 2 sum with a bit change.
        if (cards.size() == 1) {
            return -1;
        }
        unordered_map<int,int> seen;
        int len = 0;
        int ans = 100001;
        for (int i=0; i<cards.size(); i++) {
            if (seen.count(cards[i])) {
                len = i - seen[cards[i]] + 1;
                ans = min(ans, len);
            } 
            seen[cards[i]] = i;
        }
        if (ans == 100001) {
            return -1;
        }
        return ans;
        
    }
};
