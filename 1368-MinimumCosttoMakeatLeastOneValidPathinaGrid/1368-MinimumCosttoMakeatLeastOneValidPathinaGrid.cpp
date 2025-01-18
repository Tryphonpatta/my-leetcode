class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int di[5][2] = {{0,0},{0,1},{0,-1},{1,0},{-1,0}};
        bool vis[101][101] = {};
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second.first;
            int z = pq.top().second.second;
            // cout << y << " " << z << endl;
            pq.pop();
            if(y < 0 || y >= grid.size() || z < 0 || z >= grid[0].size())continue;
            if(y == grid.size() - 1 && z == grid[0].size() - 1){
                return x;
            }
            if(vis[y][z])continue;
            vis[y][z] = true;
            pq.push({x,{y + di[grid[y][z]][0],z + di[grid[y][z]][1]}});
            for(int i = 1; i < 5 ; i++){
                pq.push({x + 1,{y + di[i][0],z + di[i][1]}});
            }
        }
        return -1;
    }
};