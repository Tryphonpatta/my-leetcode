class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[301][301] = {};
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j]) {
                    dp[i][j] = 1;
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]),
                                       dp[i][j - 1]) +
                                   1;
                    }
                }
                ans += dp[i][j];
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return ans;
    }
};