class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> m;
        int ans = 1;
        for(int i = 0 ; i < matrix.size() ; i++){
            string s;
            string f;
            for(int j = 0 ; j < matrix[0].size();j++){
                s += char(matrix[i][j] + '0');
                f += char(!matrix[i][j] + '0');
            }
            // cout << s << " " << f << endl;
            ans = max(ans,max(m[s] + 1,m[f] + 1));
            m[s] ++;
            m[f] ++;
        }
        return ans;
    }
};