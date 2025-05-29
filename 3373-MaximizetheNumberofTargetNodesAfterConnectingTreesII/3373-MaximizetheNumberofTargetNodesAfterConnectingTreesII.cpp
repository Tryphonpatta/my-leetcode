// Last updated: 5/29/2025, 8:17:09 PM
class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> v1[100001];
        vector<int> v2[100001];
        for(auto e : edges1) {
            v1[e[0]].push_back(e[1]);
            v1[e[1]].push_back(e[0]);
        }
        for(auto e : edges2) {
            v2[e[0]].push_back(e[1]);
            v2[e[1]].push_back(e[0]);
        }
        queue<int> q;
        int c =0;
        int cnt1[2] = { };
        int cnt2[2] = {};
        int a1[100001] = {};
        bool vis1[100001] = {},vis2[100001]= {};
        q.push(0);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n ; i ++) {
                int x= q.front();
                q.pop();
                cnt1[c % 2] ++;
                a1[x] = c % 2;
                vis1[x] = true;
                for(auto j : v1[x]){
                    if(vis1[j])continue;
                    q.push(j);
                }
            }
            c++;
        }
        int m = 0;
        q.push(0);
        c = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n ; i ++) {
                int x= q.front();
                q.pop();
                cnt2[c % 2] ++;
                m = max(cnt2[c%2],m);
                vis2[x] = true;
                for(auto j : v2[x]){
                    if(vis2[j])continue;
                    q.push(j);
                }
            }
            c++;
        }
        vector<int> ans;
        for(int i =0; i <= edges1.size();i++){
            // cout << i << " " << cnt1[a1[i]] << endl;
            ans.push_back(cnt1[a1[i]] + m);
        }
        return ans;
    }
};