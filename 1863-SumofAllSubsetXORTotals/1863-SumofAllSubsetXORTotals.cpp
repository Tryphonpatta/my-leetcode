// Last updated: 4/6/2025, 1:27:02 AM
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i = 1 ; i < (1 << nums.size()) ; i++ ){
            int x = i;
            int j = 0;
            int X = 0;
            while (x) {
                if (x & 1){
                    X = X ^ nums[j];
                }
                j ++;
                x = x >> 1;
            }
            ans += X;
        }
        return ans;
    }
};