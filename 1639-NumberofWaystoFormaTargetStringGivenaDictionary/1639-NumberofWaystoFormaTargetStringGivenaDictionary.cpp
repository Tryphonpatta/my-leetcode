class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;
        vector<vector<int>> charFreq(wordLength,vector<int> (26,0));
        for (auto word : words) {
            for (int j = 0; j < wordLength; ++j) {
                charFreq[j][word[j] - 'a']++;
            }
        }
        long long dp[1001][1001] = {};
        for(int currWord = 0 ; currWord <= wordLength ; ++ currWord){
            dp[currWord][0] = 1;
        }
        for (int currWord = 1; currWord <= wordLength; ++currWord) {
            for (int currTarget = 1; currTarget <= targetLength; ++currTarget) {
                dp[currWord][currTarget] = dp[currWord - 1][currTarget];

                int curPos = target[currTarget - 1] - 'a';
                dp[currWord][currTarget] +=
                    (charFreq[currWord - 1][curPos] *
                     dp[currWord - 1][currTarget - 1]) %
                    MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }
        return dp[wordLength][targetLength];
    }
};