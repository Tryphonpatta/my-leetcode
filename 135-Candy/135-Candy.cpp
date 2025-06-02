// Last updated: 6/2/2025, 5:23:22 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int candies[20001] = {};
        candies[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            candies[i] = 1;
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        int ans = 0;
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
            }
            ans += candies[i - 1];
        }
        return ans + candies[ratings.size() - 1];
    }
};