class Solution {
public:
    vector<int> t[31000];
    bool vis[31000] = {};
    int ans = 0;
    long long  dfs(int n,int k,vector<int>& values) {
        if(vis[n])return 0;
        vis[n] = true;
        long long sum = values[n];
        for(int i = 0 ; i < t[n].size() ; i++){
            sum += dfs(t[n][i],k,values);
        }
        // cout << n << " " << sum << endl;
        if(sum % k == 0){
            ans ++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for(auto edge: edges) {
            t[edge[0]].push_back(edge[1]);
            t[edge[1]].push_back(edge[0]);
        }
        dfs(0,k,values);
        return ans;
    }
};