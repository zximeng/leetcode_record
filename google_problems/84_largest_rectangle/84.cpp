class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        int res = 0;
        // push one more 0 so the code does not need to check the last element
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {

            // if no longer increasing, calculate the area for the height in stack
            while (index.size() > 0 && heights[index.top()] >= heights[i]) {
                // first get the last height
                int h = heights[index.top()];
                index.pop();

                // because we know the height is strictly increasing, we can calculate the width
                // since index.top() store the index which points to the height lower than current
                // the width is i - index.top() - 1
                // if its the last item to be poped, its the smallest, thus width is i 
                int width = index.size() > 0 ? (i - index.top() - 1) : i;
                res = max(res, width * h);

            }

            index.push(i);
        }
        return res;
    }
};