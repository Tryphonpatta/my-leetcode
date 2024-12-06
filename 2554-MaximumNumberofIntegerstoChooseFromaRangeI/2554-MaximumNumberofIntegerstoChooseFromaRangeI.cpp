class Solution {
public:
    bool c[10001] = {};
    int maxCount(vector<int>& banned, int n, int maxSum) {
        for(int i = 0 ; i < banned.size() ; i++){
            c[banned[i]] = 1;
        }
        int ans = 0;
        for(int i = 1; i <= n ; i ++) {
            if(maxSum >= i && !c[i]){
                maxSum -= i;
                ans ++;
            }
            else if(maxSum < i) {
                break;
            }
        }
        return ans;
    }
};