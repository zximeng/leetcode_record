class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> c;
        for (int i : arr) {
            c[i]++;
        }
        vector<int> check;
        for (auto i : c) {
            check.push_back(i.first);
        }
        // sort according to absolute, for example -4 * 2 = -8, and if we also have -2. if we sort -4 first 
        // then we cant find -8 and algorithm would just return {}. but if -2 appears first, the algorithm
        // would find -4 and continue.
        sort(check.begin(), check.end(), [](int i, int j) {return abs(i) < abs(j);});

        for (int i : check) {
            if (c[i] > c[2*i]) {
                return false;
            }
            for (int j = 0; j < c[i]; j++) {
                c[2*i]--;
            }
        }
        return true;
    }
};