class Solution {
public:
    int bits[33] = {};
    int val() {
        int sum = 0;
        int ex = 1;
        for(int i =0 ; i < 30;i ++){
            sum += ex * (bits[i] > 0 ? 1 : 0) ;
            ex *= 2;
        }
        return sum;
    }
    void increaseBit (int n){
        int i = 0;
        while(n) {
            if(n & 1)
                bits[i] ++;
            n = n >> 1;
            i ++ ;
        }
    }
    void decreaseBit (int n){
        int i = 0;
        while(n) {
            if (n & 1)
                bits[i] --;
            n = n >> 1;
            i++;
        }
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int cur = 0;
        int ans = INT_MAX;
        while (right < nums.size()) {
            increaseBit(nums[right]);
            int x = val();
            while(x >= k && left < nums.size()){
                ans = min(ans,right - left + 1);
                decreaseBit(nums[left]);
                left += 1;
                x = val();
            }
            right ++;
        }
        if(ans <= 0)return 1;
        return ans == INT_MAX ? -1 : ans;
    }
};