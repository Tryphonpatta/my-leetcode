class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int> s;
        bool vis[100001] = {};
        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int ans = -1;
        for(int i = 0; i < nums.size();i ++){
            if(vis[nums[i]])continue;
            int cnt = 0;
            long long int tmp = nums[i];
            auto itr = s.find(tmp);
            while(itr != s.end()){
                if(tmp >= INT_MAX)
                    break;
                vis[nums[i]] = 1;
                itr = s.find(tmp * tmp);
                cnt ++;
                tmp = tmp * tmp;
            }
            if(cnt > 1)
                ans = max(ans,cnt);
        }
        return ans;
    }
};