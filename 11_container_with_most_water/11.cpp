class Solution {
public:
    int maxArea(vector<int>& height) {

        // 1. consider the outer most two lines, the length at the bottom is the same but the lower bound determine the area.
        // 2. if keeping the lower bound, then the area would only decrease. So the only rational way should be discarding the lower bound
        // 3. then the problem becomes finding the maximum of (this area , rest of the lines). so keep removing the lower bound should be the answer

        // using two pointer to remove the lower bound
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        int maxArea = 0;
        int len = 0;
        int lower = 0;
        while (left < right) {
            len = right - left;
            if (height[left] > height[right]) {
                lower = height[right];
                right--;
            } else {
                lower = height[left];
                left++;
            }
            area = lower * len;
            maxArea = max(area, maxArea);
            
        }
        return maxArea;
    }
};