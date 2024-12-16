class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int dp[201][201] = {};
        int n = triangle.size();
        dp[0][0] = triangle[0][0];
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j < i + 1 ; j ++){
                dp[i][j] = INT_MAX;
                if(j - 1 >= 0 ){
                    dp[i][j] = min(dp[i][j], dp[i-1][j - 1] + triangle[i][j]);
                }
                if(j <= i - 1){
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + triangle[i][j]);
                }
            }
        }
        // for(int i = 0 ; i < n ; i ++){
        //     for(int j = 0 ; j < i + 1 ; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            ans = min(dp[n - 1][j],ans);
        }
        return ans;
    }
};