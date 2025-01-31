class Solution {
public:
    int dp[260000] = {};
    int group[502][502] = {};
    bool vis[502][502] = {};
    int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int rec(int i, int j, vector<vector<int>>& grid, int g) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        if (grid[i][j] == 0)
            return 0;
        if (vis[i][j])
            return 0;
        vis[i][j] = true;
        int sum = 1;
        group[i][j] = g;
        for (int k = 0; k < 4; k++) {
            sum += rec(i + di[k][0], j + di[k][1], grid, g);
        }
        return sum;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int g = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0)
                    continue;
                if (!vis[i][j]) {
                    dp[g] = rec(i, j, grid, g);
                    g++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int temp = 1;
                    bool c[300000] = {};
                    unordered_set<int> neighbor;
                    for (int k = 0; k < 4; k++) {
                        int x = i + di[k][0];
                        int y = j + di[k][1];
                        if (x < 0 || y < 0 || x >= n || y >= m)
                            continue;
                        neighbor.insert(group[x][y]);
                    }
                    for(int id : neighbor){
                        temp += dp[id];
                    }
                    ans = max(ans, temp);
                } else {
                    ans = max(ans, dp[group[i][j]]);
                    // cout << ans << "\t";
                }
            }
        }
        return ans;
    }
};
