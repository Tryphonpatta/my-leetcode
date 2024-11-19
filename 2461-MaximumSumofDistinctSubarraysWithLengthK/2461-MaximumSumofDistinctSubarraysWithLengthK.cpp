class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int dup = 0;
        map<int,int> m;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0 ; i < k - 1; i++){
            if(m[nums[i]] == 1){
                dup ++;
            }
            m[nums[i]] += 1;
            sum += nums[i];
        }
        int left = 0, right = k - 1;
        while(right < nums.size()) {
            if(m[nums[right]] == 1){
                dup ++;
            }
            m[nums[right]] ++;
            sum += nums[right];
            // cout << sum << " " << left << " " << right << " " <<dup << endl ; 
            if(dup == 0){
                ans = max(ans,sum);
            }
            sum -= nums[left];
            m[nums[left]] --;
            if(m[nums[left]] == 1){
                dup--;
            }
            left ++;
            right ++;
        }
        return ans;
    }
};