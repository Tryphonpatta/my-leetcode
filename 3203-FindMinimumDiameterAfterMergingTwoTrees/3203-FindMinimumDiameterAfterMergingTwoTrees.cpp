class Solution {
public:
    vector<int> t[2][100001];
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        for(auto edge : edges1 ){
            t[0][edge[0]].push_back(edge[1]);
            t[0][edge[1]].push_back(edge[0]);
        }
        for(auto edge : edges2 ){
            t[1][edge[0]].push_back(edge[1]);
            t[1][edge[1]].push_back(edge[0]);
        }
        auto [f1,dd] = bfs(0,0);
        // cout << f1 << " " << dd << endl;
        auto [ff,di1] = bfs(f1,0);
        // cout << ff << " " << di1 << endl;
        auto [f2,ddd] = bfs(0,1);
        auto [f,di2] = bfs(f2,1);
        // cout << di1 << " " << di2 << " " << (di1 + 1)/2 + (di2+1)/2 + 1;
        return max(max(di1,di2),(di1 + 1)/2 + (di2+1)/2 + 1);
    }
    pair<int,int> bfs(int src,int tree) {
        queue<pair<int,int>> q;
        bool vis[100001] = {};
        q.push({src,0});
        int maxDist = 0;
        int dest = 0;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(vis[x])continue;
            vis[x] = true;
            dest = x;
            maxDist = y;
            for(auto p : t[tree][x]){
                q.push({p,y + 1});
            }
        }
        return {dest,maxDist};
    } 
};