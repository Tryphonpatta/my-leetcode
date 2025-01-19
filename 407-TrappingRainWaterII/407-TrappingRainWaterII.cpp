class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int di[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = heightMap.size();
        int m = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        for(int i = 0; i < heightMap[0].size(); i++){
            pq.push({heightMap[0][i],{0,i}});
            pq.push({heightMap[heightMap.size() - 1][i],{heightMap.size() - 1,i}});
        }
        for(int i = 1 ; i < n - 1 ; i ++){
            pq.push({heightMap[i][0],{i,0}});
            pq.push({heightMap[i][m - 1],{i,m - 1}});
        }
        bool vis[201][201] = {};
        int ans = 0;
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second.first;
            int z = pq.top().second.second;
            pq.pop();
            if(y < 0 || z < 0 || y >= n || z >= m)continue;
            vis[y][z] = true;
            for(int i = 0 ; i < 4 ; i ++){
                int yy = y + di[i][0];
                int zz = z + di[i][1];
                if(yy < 0 || zz < 0 || yy >= n || zz >= m || vis[yy][zz])continue;
                vis[yy][zz] = true;
                if(heightMap[yy][zz] < x)
                {
                    ans += x - heightMap[yy][zz];
                    pq.push({x,{yy,zz}});
                }
                else pq.push({heightMap[yy][zz],{yy,zz}});
            }
        }
        return ans;
    }
};