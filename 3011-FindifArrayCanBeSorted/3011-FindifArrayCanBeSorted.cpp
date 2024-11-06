class Solution {
public:
    int countBit(int n){
        int cnt = 0 ;
        while(n > 0) {
            if(n & 1)cnt ++;
            n = n >> 1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() - i - 1 ; j++){
                if(nums[j] > nums[j + 1] && countBit(nums[j]) == countBit(nums[j + 1])){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        for(int i =  1 ; i < nums.size() ; i++){
            // cout << nums[i] << endl;
            if(nums[i] < nums[i - 1])return false;
        }
        return true;
    }
};