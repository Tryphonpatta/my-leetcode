// Last updated: 4/24/2025, 12:22:36 PM
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> cnt;
        int right = 0;
        unordered_set<int> d(nums.begin(),nums.end());
        int dis = d.size();
        for(int left = 0 ; left < nums.size() ;left++){
            if (left > 0){
                int remove = nums[left - 1];
                cnt[remove] --;
                if (cnt[remove] == 0)cnt.erase(remove);
            }
            while( right < nums.size() && cnt.size() < dis) {
                int add = nums[right];
                cnt[add] ++;
                right ++;
            }
            if(cnt.size() == dis){
                ans += (nums.size() - right + 1);
            }
        }
        return ans;
    }
};