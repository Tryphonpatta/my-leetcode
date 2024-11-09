class Solution {
public:
    int isValid(int i,int j, vector<vector<int>>& grid){
        if(i >= grid.size() || j >= grid[0].size())
            return -1;
        return grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int di[2][2] = {{0,1},{1,0}};
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({grid[0][0],{0,0}});
        bool vis[201][201] = {};
        while(!pq.empty()){
            int z = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(vis[x][y])continue;
            vis[x][y] = 1;
            if(x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                return z;
            }
            for(int i = 0 ;i < 2; i ++){
                if(isValid(x + di[i][0],y + di[i][1],grid) != -1){
                    int xx = x + di[i][0];
                    int yy = y + di[i][1];
                    pq.push({z + grid[xx][yy],{xx,yy}});
                }
            }
        }
        return -1;
    }
};