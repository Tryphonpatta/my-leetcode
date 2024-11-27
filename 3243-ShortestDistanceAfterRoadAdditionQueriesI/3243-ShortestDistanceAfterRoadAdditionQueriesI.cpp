class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> v[501];
        vector<int> ans;
        for(int i = 1; i < n ; i ++){
            v[i - 1].push_back(i);
        }
        for(int i = 0 ; i < queries.size() ; i++){
            v[queries[i][0]].push_back(queries[i][1]);
            bool vis[501] = {};
            queue<pair<int,int>> q;
            q.push({0,0});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n - 1){
                    ans.push_back(y);
                    break;
                }
                if(vis[x])continue;
                vis[x] = true;
                for(int j = 0 ; j < v[x].size() ; j++){
                    
                    q.push({v[x][j], y + 1});
                }
            }
        }
        return ans;
    }
};