// Last updated: 3/22/2025, 11:00:44 PM
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int g[51] = {};
        vector<int> v[51] = {};
        for(auto edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        bool vis[51] = {};
        int ans = 0;
        for(int i = 0 ; i < n ; i ++) {
            if(vis[i])continue;
            queue<int> q;
            q.push(i);
            int edge = 0;
            int node = 0;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                if(vis[x])continue;
                vis[x] = true;
                node ++;
                edge += v[x].size();
                for(int j = 0 ; j < v[x].size() ; j++){
                    if(vis[v[x][j]])continue;
                    q.push(v[x][j]);
                }
            }
            if(node * (node - 1) == edge)ans ++;
        }
        return ans;
    }
};