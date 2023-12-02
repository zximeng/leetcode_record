class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = 0;

        vector<int> nums;

        while (left < m || right < n) {
            if (left == m) {
                while (right < n) {
                    nums.push_back(nums2[right++]);
                }
            } else if (right == n) {
                while (left < m) {
                    nums.push_back(nums1[left++]);
                }
            } else if (nums1[left] >= nums2[right]) {
                nums.push_back(nums2[right++]);
            } else {
                nums.push_back(nums1[left++]);
            }

        }

        int median = (m + n) / 2;
        if ((m + n) % 2) {
            return (double)nums[median];
        } else {
            return ((double)nums[median -1] + (double)nums[median]) /2;
        }
        
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = 0;

        int median = (m + n) / 2;

        vector<int> nums;

        while (left < m || right < n) {
            if (left == m) {
                while (right < n) {
                    nums.push_back(nums2[right++]);
                }
            } else if (right == n) {
                while (left < m) {
                    nums.push_back(nums1[left++]);
                }
            } else if (nums1[left] >= nums2[right]) {
                nums.push_back(nums2[right++]);
            } else {
                nums.push_back(nums1[left++]);
            }

            if (nums.size() >= median) {
                if ((m + n) % 2) {
                    return (double)nums[median];
                } else {
                    return ((double)nums[median -1] + (double)nums[median]) /2;
                }
            }

        }
        
    }
};