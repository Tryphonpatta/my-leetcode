// Last updated: 3/27/2025, 11:16:26 AM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> m;
        int dominant = 0;
        int freq = 0;
        for(auto num : nums) {
            m[num] ++;
        }
        unordered_map<int,int> cnt;
        for(int i = 0 ; i < nums.size() ; i++){
            cnt[nums[i]] ++;
            if(cnt[nums[i]] > freq){
                freq = cnt[nums[i]];
                dominant = nums[i];
            }
            if(freq * 2 > i + 1)
            {
                if((m[dominant] - cnt[dominant])*2 > nums.size() - i - 1){
                    return i;
                }
            }
        }
        return -1;
    }
};