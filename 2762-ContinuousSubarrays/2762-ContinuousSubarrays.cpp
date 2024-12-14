class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0 ,right = 0;
        long long ans = 0 ;
        map<int,int> m;
        while(right < nums.size()) {
            m[nums[right]] ++;
            while(m.rbegin()->first - m.begin()->first > 2) {
                m[nums[left]]--;
                if(m[nums[left]] == 0)
                    m.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right ++;
        }
        return ans;
    }
};