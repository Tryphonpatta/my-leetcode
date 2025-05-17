// Last updated: 5/17/2025, 2:49:18 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {};
        for(auto num : nums){
            cnt[num] ++;
        }
        int index  =0 ;
        for(int i = 0; i < 3;i++){
            for(int j = 0;j < cnt[i] ;j++){
                nums[index] = i;
                index ++;
            }
        }
    }
};