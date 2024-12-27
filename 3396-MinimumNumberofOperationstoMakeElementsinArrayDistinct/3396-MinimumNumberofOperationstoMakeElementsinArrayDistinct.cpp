class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bool a[200] = {};
        int ans = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if(a[nums[i]]){
                ans = i;
                break;
            }
            a[nums[i]] = true;
        }
        if(ans == -1)return 0;
        return (ans+3) / 3;
    }
};