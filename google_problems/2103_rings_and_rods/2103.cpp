class Solution {
public:
    int countPoints(string rings) {
        set<char>rods[10];
        for (int i=0; i<rings.size(); i+=2) {
            char color = rings[i];
            int rod = rings[i+1];
            rods[rod-'0'].insert(color);
        }
        int res = 0;
        for (int i=0; i<10; i++) {
            if (rods[i].size() == 3) {
                res++;
            }
        }
        return res;
    }
};