class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for(int i =0 ; i < nums.size(); i++){
            sum += nums[i];
        }
        int pre = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() - 1 ;i++){
            pre += nums[i];
            sum -= nums[i];
            if((pre - sum) % 2 ==0){
                ans ++;
            }
        }
        return ans;
    }
};