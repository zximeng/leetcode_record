class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //first sort the array
        sort(nums.begin(), nums.end());
        vector<int> res;
        //then binary search for the left bound and right bound
        int leftBound = -1;
        int rightBound = -1;
        int mid;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if (nums[left] == target) {
            leftBound = left;
        }
        left = 0;
        right = nums.size();
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] <= target) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (nums[right] == target) {
            rightBound = right;
        }

        for(int i = leftBound; i <rightBound+1; i++) {
            res.push_back(i);
        }
        return res;   
    }
};