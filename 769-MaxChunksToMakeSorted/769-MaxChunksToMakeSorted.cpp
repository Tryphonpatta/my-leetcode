class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, m = 0;
        for (int i = 0; i < n; i++) {
            m = max(m, arr[i]);

            if (m == i) {
                ans++;
            }
        }

        return ans;
    }
};