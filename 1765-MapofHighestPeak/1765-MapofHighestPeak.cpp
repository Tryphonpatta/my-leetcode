class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> g(n,(vector<int> (m, 0)));
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j ++){
                if(isWater[i][j])q.push({0,{i,j}});
            }
        }
        bool vis[1001][1001] = {};
        int di[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second.first;
            int z = q.front().second.second;
            q.pop();
            if(y < 0 || z < 0 || y >= n || z >= m)continue;
            if(vis[y][z])continue;
            // cout << y << " " << z << endl;
            g[y][z] = x;
            vis[y][z] = true;
            for(int i = 0 ; i < 4 ; i++){
                q.push({x + 1,{y + di[i][0],z + di[i][1]}});
            }
        }
        return g;
    }
};