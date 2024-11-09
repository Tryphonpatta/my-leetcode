class Solution {
public:
    int dp[101][101] = {};
    int rec(int i , int j,vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        if(i >= m || j >= n )return 0;
        if(obstacleGrid[i][j] == 1)
            return 0;
        if(i == m - 1 && j == n - 1)return 1;
        if(dp[i][j])
            return dp[i][j];
        dp[i][j] = rec(i+1,j,obstacleGrid) + rec(i,j+1,obstacleGrid);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return rec(0,0,obstacleGrid);
    }
};