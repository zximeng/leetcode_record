class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int top = 0;
        int bot = m - 1;

        vector<int> res(2, 0);

        while (top <= bot) {

            int mid = top + (bot - top) / 2;
            
            int local_max = 0;
            int max_index = 0;
            for (int i = 0; i < n; i++) {
                if (mat[mid][i] > local_max) {
                    local_max = mat[mid][i];
                    max_index = i;
                }
            }

            if(m == 1) {
                return {0, max_index};
            }

            if ((mid > 0  && mid < m - 1\
            && local_max > mat[mid + 1][max_index] \
            && local_max > mat[mid - 1][max_index]) \
            || (mid == 0 \
            && local_max > mat[mid + 1][max_index]) \
            || (mid == m -1 \
            && local_max > mat[mid - 1][max_index])
            ) {
                return {mid, max_index};
            } else if (mid > 0 && local_max < mat[mid - 1][max_index]) {
                bot = mid - 1;
            } else {
                top = mid + 1;
            }
        }
        return {-1, -1};

    }
};