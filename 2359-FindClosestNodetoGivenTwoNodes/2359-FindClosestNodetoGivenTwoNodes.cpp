// Last updated: 5/30/2025, 1:58:34 PM
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int vis1[100001] = {};
        memset(vis1,-1,sizeof(vis1));
        queue<pair<int, int>> q;
        q.push({node1, 0});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (vis1[x] != -1)
                continue;
            vis1[x] = y;
            if (edges[x] != -1) {
                q.push({edges[x], y + 1});
            }
        }
        int vis2[100001] = {};
        memset(vis2,-1,sizeof(vis2));
        q.push({node2, 0});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (vis2[x] != -1)
                continue;
            vis2[x] = y;
            if (edges[x] != -1) {
                q.push({edges[x], y + 1});
            }
        }
        int ans = -1;
        int max_dis = INT_MAX;
        for(int i = 0; i < edges.size() ; i++){
            if(vis1[i] != -1 && vis2[i] != -1) {
                int x = max(vis1[i],vis2[i]);
                if(x < max_dis) {
                    max_dis = x;
                    ans = i;
                }
            }
        }
        return ans;
    }
};