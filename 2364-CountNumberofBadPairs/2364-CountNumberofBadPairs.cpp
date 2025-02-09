class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans = nums.size() * (nums.size() -1 ) /2;
        unordered_map<int,int> h;
        for(int i = 0 ; i < nums.size() ; i++){
            int x = nums[i] - i;
            ans -= h[x];
            h[x] ++;
        }
        return ans;
    }
};