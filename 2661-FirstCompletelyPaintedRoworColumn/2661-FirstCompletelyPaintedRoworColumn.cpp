class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int row[100002] = {};
        int col[100002] = {};
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                row[mat[i][j]] = i;
                col[mat[i][j]] = j;
            }
        }
        int cntRow[100002] = {};
        int cntCol[100002] = {};
        for(int i = 0 ; i < arr.size() ;i++){
            cntRow[row[arr[i]]] ++;
            cntCol[col[arr[i]]] ++;
            if(cntRow[row[arr[i]]] == m || cntCol[col[arr[i]]] == n)return i;
        }
        return -1;

    }
};