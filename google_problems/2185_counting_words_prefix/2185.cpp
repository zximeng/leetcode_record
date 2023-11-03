class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int len = pref.size();
        int res = 0;
        for (auto item:words) {
            if (item.substr(0,len) == pref) {
                res++;
            }
        }
        return res;
    }
};