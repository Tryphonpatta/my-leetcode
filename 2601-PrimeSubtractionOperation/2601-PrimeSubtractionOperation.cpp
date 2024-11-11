class Solution {
public:
    bool p[1010];
    void sieve(){
        p[0] = 1;
        p[1] = 1;
        for(int i = 2 ;i <= 1000; i++){
            if(p[i])continue;
            for(int j = i * i; j <= 1000 ;j += i){
                p[j] = 1;
            }
        }
    }
    bool primeSubOperation(vector<int>& nums) {
        sieve();
        for(int i = nums.size() - 2 ; i >=0;i--){
            if(nums[i] >= nums[i + 1]){
                int prime = 0;
                for(int j = nums[i] - nums[i + 1] + 1 ; j <= 1000 && j < nums[i]; j++){
                    if(!p[j]){
                        prime = j;
                        break;
                    }
                }
                nums[i] -= prime;
            }
            // cout << nums[i] << " ";
            if(nums[i] >= nums[i + 1])
                return false;
        }
        return true;
    }
};