class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int di[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ;j++){
                int s = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                // cout << j << endl;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    if(x < 0 || y < 0|| x >= grid.size() || y >= grid[0].size())continue;
                    if(grid[x][y] == 0)continue;
                    s += grid[x][y];
                    // cout << x << " "<< y << endl;
                    grid[x][y] = 0;
                    for(int k =0 ; k < 4; k++){
                        q.push({x + di[k][0], y + di[k][1]});
                    }
                }
                ans = max(ans,s);
            }
        }
        return ans;

    }
};