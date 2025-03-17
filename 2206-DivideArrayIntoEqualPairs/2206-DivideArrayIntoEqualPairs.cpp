class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int m[501] = {};
        for(int num : nums) {
            m[num] ++;
        }
        for(int i = 1; i <= 500;i++){
            if(m[i] % 2)return false;
        }
        return true;
    }
};