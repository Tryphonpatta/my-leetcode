class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long sum = 0,s = 0;
        long long ans = LONG_LONG_MAX;
        for(int i =0 ; i < grid[0].size() ; i++)sum += grid[0][i];
        for(int i = 0; i < grid[0].size() ; i++){
            sum -= grid[0][i];
            ans = min(ans, max(sum,s));
            s += grid[1][i];
        }
        return ans;
    }
};