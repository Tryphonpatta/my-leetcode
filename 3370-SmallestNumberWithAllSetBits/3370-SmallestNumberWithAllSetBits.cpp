class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int sum= 0;
        int ans = INT_MIN;
        map<int,int> m;
        for(auto num : nums) {
            sum += num;
            m[num] += 1;
        }
        for(auto num : nums){
            if((sum - num) % 2 == 0){
                int cnt = m[(sum - num) / 2] - (((sum - num) / 2) == num);
                if(cnt){
                    // cout << cnt << endl;
                    // cout<< num << " " << (sum - num) / 2 << endl;
                    ans = max(ans, num);
                }
            }
        }
        return ans;
    }
};