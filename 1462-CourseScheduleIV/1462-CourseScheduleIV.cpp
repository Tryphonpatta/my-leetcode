class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool ans[101][101] = {};
        vector<int> adj[101];
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i = 0 ; i < numCourses ; i++){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int x = q.front();
                q.pop();
                if(ans[i][x])continue;
                ans[i][x] = true;
                for(int j = 0 ; j < adj[x].size() ; j++){
                    q.push(adj[x][j]);
                }
            }
        }
        vector<bool> a;
        for(int i = 0; i < queries.size() ; i++){
            a.push_back(ans[queries[i][0]][queries[i][1]]);
        }
        return a;
    }
};