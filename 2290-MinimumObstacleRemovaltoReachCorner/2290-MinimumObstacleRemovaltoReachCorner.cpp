class Solution {
#define f first
#define s second
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int di[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; 
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int z = pq.top().f;
            int x = pq.top().s.f;
            int y = pq.top().s.s;
            pq.pop();
            if(x < 0 || y < 0 || x >= n || y >=m)continue;
            if(vis[x][y])continue;
            vis[x][y] = true;
            if(grid[x][y])
                z+= 1;
            if(x == n - 1 && y == m - 1)
                return z;
            for(int i = 0 ; i < 4 ;i ++){
                int xx = x + di[i][0];
                int yy = y + di[i][1];
                pq.push({z,{xx,yy}});
            }
        }   
        return -1;
    }
};