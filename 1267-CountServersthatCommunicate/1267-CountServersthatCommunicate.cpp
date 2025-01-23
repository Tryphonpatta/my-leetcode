class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rowCnt[251] = {};
        int colCnt[251] = {};
        for(int i =0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j]){
                    rowCnt[i] ++;
                    colCnt[j] ++;
                }
            }
        }
        int ans = 0;
        for(int i = 0 ; i < grid.size() ;i++){
            for(int j = 0 ; j < grid[0].size() ;j++){
                if(grid[i][j] && (rowCnt[i] > 1 || colCnt[j] > 1) ){
                    ans ++;
                }
            }
        }
        return ans;
    }
};