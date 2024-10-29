class Solution {
public:
    int dp[1001][1001];
    vector<vector<int>> a;
    int n,m;
    int ans = 0;
    int di[3][2] = {{-1,1},{0,1},{1,1}};
    int rec(int i, int j, int prev){
        if(i < 0 || j < 0 || i >= n || j >= m)return 0;
        if(prev >= a[i][j] )return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 1;
        for(int k =0 ; k < 3; k++)
        {
            dp[i][j] = max(1 + rec(i + di[k][0],j + di[k][1],a[i][j]),dp[i][j]);
        }
        return dp[i][j];
    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        a = grid;
        for(int i = 0 ; i < n; i++)
        {
            // cout << rec(i,0,0) << endl;
            ans = max(ans,rec(i,0,0));
        }
        return ans == 1 ? 0 : ans - 1;
    }
};