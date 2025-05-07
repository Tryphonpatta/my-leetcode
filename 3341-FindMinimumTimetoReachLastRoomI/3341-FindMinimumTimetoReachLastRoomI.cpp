// Last updated: 5/7/2025, 3:33:55 PM
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        int di[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        bool vis[51][51] = {};
        while(!pq.empty()){
            int t = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            if(x == moveTime.size() - 1 && y == moveTime[0].size() - 1)
                return t;
            if(x < 0 || y < 0 || x >= moveTime.size() || y >= moveTime[0].size())continue;
            if(vis[x][y])continue;
            vis[x][y] = true;
            for(int i = 0; i < 4 ;i ++){
                int newx = x + di[i][0];
                int newy = y + di[i][1];
                if(newx < 0 || newy < 0 || newx >= moveTime.size() || newy >= moveTime[0].size())continue;
                pq.push({max(t + 1, moveTime[newx][newy] + 1), {newx,newy}});
            }
        }
        return -1;
    }
};