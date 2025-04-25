// Last updated: 4/25/2025, 2:53:12 PM
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int cnt[100002] = {};
        unordered_map<int, int> m;
        cnt[0] = 0;
        for (int i = 1; i <= nums.size(); i++) {
            cnt[i] += cnt[i - 1];
            cnt[i] += nums[i - 1] % modulo == k ? 1 : 0;
        }
        long long ans = 0;
        for (int i = 0; i <= nums.size(); i++) {
            ans += m[(cnt[i] + modulo - k) % modulo];
            m[cnt[i] % modulo]++;
        }
        return ans;
    }
};