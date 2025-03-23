// Last updated: 3/23/2025, 10:35:21 PM
class Solution {
public:
const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> v[201];
        for(int i = 0 ; i < roads.size() ; i++){
            v[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            v[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        int cnt[201] = {};
        vector<long long> shortestTime(n, LLONG_MAX);
        cnt[0] = 1;
        while(!pq.empty()){
            long long x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            if(x > shortestTime[y])continue;
            for(int i = 0 ; i < v[y].size() ;i ++){
                if(x + v[y][i].second < shortestTime[v[y][i].first]) {
                    cnt[v[y][i].first] = cnt[y];
                    shortestTime[v[y][i].first] = x + v[y][i].second;
                    pq.push({shortestTime[v[y][i].first], v[y][i].first});
                }
                else if (x + v[y][i].second == shortestTime[v[y][i].first]){
                    cnt[v[y][i].first] = (cnt[v[y][i].first] + cnt[y]) % MOD;
                }
            }
        }
        return cnt[n - 1];
    }
};