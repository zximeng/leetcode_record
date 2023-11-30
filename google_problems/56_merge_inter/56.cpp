class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() <= 1) {
            return intervals;
        }

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int new_left = intervals[i][0];
            int new_right = intervals[i][1];
            if (new_left <= right) {
                right = max(right, new_right);
            } else {
                ans.push_back({left, right});
                left = new_left;
                right = new_right;
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};