class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int ans = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int mi = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0)
                    cnt++;
                mi = min(mi, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
                // cout << matrix[i][j] << " ";
            }
        }
        if (cnt % 2 == 0)
            return ans;
        return ans - 2 * mi;
    }
};