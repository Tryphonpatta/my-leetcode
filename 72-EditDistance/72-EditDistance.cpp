class Solution {
public:
    int minDistance(string word1, string word2) {
        string temp = word2;
        word2 = word1;
        word1 = temp;
        int dp[600][600] = {};
        for(int i = 0 ; i <= word1.size() ; i++){
            dp[i][0] = i;
        }
        for(int i = 0 ; i <= word2.size() ; i++){
            dp[0][i] = i;
        }
        for(int i = 1 ; i <= word1.size() ;i ++){
            int ii = i -1;
            for(int j = 1 ; j <= word2.size() ; j++){
                int jj = j - 1;
                if(word2[jj] == word1[ii]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j],min(dp[i][j - 1],dp[i - 1][j - 1])) + 1;
                }
            }
        }
        // for(int i = 0 ; i <= word1.size() ; i++){
        //     for(int j = 0 ;j <= word2.size();j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[word1.size()][word2.size()];
    }
};