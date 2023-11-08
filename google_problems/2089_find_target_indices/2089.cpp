class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        //first sort the array
        sort(nums.begin(), nums.end());
        vector<int> res;
        int left = 0;
        int right = nums.size() - 1;
        int leftBound = -1;
        int rightBound = -1;

        // Find the left boundary
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                right = mid - 1;
                leftBound = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left = 0;
        right = nums.size() - 1;

        // Find the right boundary
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                left = mid + 1;
                rightBound = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (leftBound != -1 && rightBound != -1) {
            for (int i = leftBound; i <= rightBound; i++) {
                res.push_back(i);
            }
        }

        return res;
    }
};
