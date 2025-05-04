// Last updated: 5/4/2025, 7:47:58 PM
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int a[10][10] = {};
        for(int i = 0; i < dominoes.size() ;i ++){
            a[min(dominoes[i][0],dominoes[i][1])][max(dominoes[i][0],dominoes[i][1])] ++;
        }
        int ans = 0;
        for(int i = 1 ; i <= 9 ; i++){
            for(int j = i ; j <= 9 ;j ++){
                ans += (a[i][j] - 1) * (a[i][j]) / 2;
            }
        }
        return ans;
    }
};