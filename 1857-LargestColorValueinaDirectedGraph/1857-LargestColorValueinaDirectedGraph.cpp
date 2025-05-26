// Last updated: 5/26/2025, 5:56:28 PM
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        int indegree[100001] = {};
        for(auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]] ++;
        }
        vector<vector<int>> dp(n, vector<int>(26,0));
        queue<int> q;

        for(int i = 0 ; i < n ; i ++ ){
            if(indegree[i] == 0)q.push(i);
            dp[i][colors[i] - 'a'] = 1;
        }
        int v = 0;
        int maxColor = 0;
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            v ++;
            for(int i: adj[x]){
                for(int c=0 ; c < 26 ; ++c){
                    int inc = (colors[i] - 'a' == c) ? 1 : 0;
                    dp[i][c] = max(dp[i][c], dp[x][c] + inc);
                }

                indegree[i]--;
                if (indegree[i] == 0) q.push(i);
            }
            maxColor = max(maxColor, *max_element(dp[x].begin(), dp[x].end()));
        }
        return v == n ? maxColor : -1;
    }
};