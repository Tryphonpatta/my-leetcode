class Solution {
public:
    long long findScore(vector<int>& nums) {
        bool marked[100001] = {};
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        long long  ans = 0;
        while (!pq.empty()) {
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            if (marked[y])
                continue;
            ans += x;
            if (y - 1 >= 0)
                marked[y - 1] = true;
            if (y + 1 < nums.size())
                marked[y + 1] = true;
            marked[y] = true;
        }
        return ans;
    }
};