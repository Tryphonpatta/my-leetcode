// Last updated: 3/27/2025, 1:01:45 AM
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j ++){
                v.push_back(grid[i][j]);
            }
        }
        sort(v.begin(),v.end());
        int median = v[v.size() / 2];
        int ans= 0;
        for(auto num : v){
            if(abs(num - median) % x != 0)return -1;
            ans += abs(num - median) / x;
        }
        return ans;
    }
};