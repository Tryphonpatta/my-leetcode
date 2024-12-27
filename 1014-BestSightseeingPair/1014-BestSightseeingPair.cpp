class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int dp = values[0];
        int ans = 0;
        for(int i = 1 ; i < values.size() ;i++){
            ans = max(ans,dp + values[i] -i);
            if(values[i] + i > dp){
                dp = values[i] + i;
            }
        }
        return ans;
    }
};