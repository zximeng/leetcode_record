class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        // calculate the height
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j]) {
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    ans = max(ans, matrix[i][j] * (j + 1));
                } else {
                    break;
                }

            }
        }
        return ans;
        
    }
};