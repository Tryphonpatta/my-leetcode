// Last updated: 3/29/2025, 12:47:15 AM
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int,int>> qs;
        for(int i = 0 ; i < queries.size();i++) {
            qs.push_back({queries[i],i});
        }
        sort(qs.begin(),qs.end());
        int cnt = 0;
        bool vis[1001][1001] = {};
        int di[4][2] = {{0,1}, {0, -1}, {1,0}, {-1,0}};
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >  pq;
        pq.push({grid[0][0],{0,0}});
        for(auto q : qs) {
            while(!pq.empty() && q.first > pq.top().first){
                int x = pq.top().first;
                int y = pq.top().second.first;
                int z = pq.top().second.second;
                pq.pop();
                // cout << y << " " << z << "  : " << cnt << endl;
                if(vis[y][z])continue;
                vis[y][z] = true;
                cnt ++;
                for(int i = 0 ; i < 4 ; i++){
                    int newI = y + di[i][0];
                    int newJ = z + di[i][1];
                    if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size())continue;
                    if(vis[newI][newJ])continue;
                    pq.push({grid[newI][newJ],{newI,newJ}});
                }
            }
            ans[q.second] = cnt;
        }
        return ans;
    }
};