class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        vector<pair<int,int>> sweepline;
        for (auto it : intervals) {
            sweepline.push_back(make_pair(it.start, 1));
            sweepline.push_back(make_pair(it.end, -1));
        }
        sort(sweepline.begin(), sweepline.end());

        int room = 0;
        int pre_sum = 0;
        for (auto dot : sweepline) {
            pre_sum += it.second;
            room = max(room, pre_sum);
        }

        return room;

    }
};