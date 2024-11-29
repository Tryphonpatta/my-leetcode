class Solution {
public:
    bool check(vector<vector<int>>& grid,int x,int y){
        int di[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0 ; i < 4 ; i ++){
            int xx = x + di[i][0];
            int yy = y + di[i][1];
            if(xx < 0 || yy < 0 || xx >= grid.size() || yy >= grid[0].size())
                continue;
            if(grid[xx][yy] <= grid[x][y])return true;
        }
        return false;
    }
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int di[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        if(grid[0][1] > 1 && grid[1][0] > 1)return -1;
        pq.push({0, {0, 0}});
        while(!pq.empty()){
            int z = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == n-1 && y == m-1)return z;
            if(z < grid[x][y])continue;
            if(vis[x][y])continue;
            vis[x][y] = true;
            // bool s = check(grid,x,y);
            for(int i = 0 ; i < 4;  i ++){
                int xx = x + di[i][0];
                int yy = y + di[i][1];
                if(xx < 0 || yy < 0 || xx >= n || yy >= m)continue;
                if(grid[xx][yy] <= z + 1)
                    pq.push({z + 1, {xx,yy}});
                // else if(s) {
                else {
                    pq.push({grid[xx][yy] + ((grid[xx][yy]-z+1)%2), {xx,yy}});
                }
                // }
            }
        }
        return -1;
    }
};