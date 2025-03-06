class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        bool c[2501] = {};
        int sum = 0;
        int dup = 0;
        int e =
            (grid.size() * grid.size()) * (grid.size() * grid.size() + 1) / 2;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                if (c[grid[i][j]]) {
                    dup = grid[i][j];
                    continue;
                }
                c[grid[i][j]] = 1;
                sum += grid[i][j];
            }
        }
        if (e - sum < 0)
            return {dup, sum - e};
        else
            return {dup, e - sum};
    }
};