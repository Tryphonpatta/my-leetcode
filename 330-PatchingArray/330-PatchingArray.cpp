// Last updated: 4/21/2025, 2:08:20 PM
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int result = 0;
        int i = 0;
        while(miss <= n) {
            
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i ++;
            }
            else {
                miss += miss;
                result ++;
            }
            // cout << miss << endl;
        }
        return result;
    }
};