class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        int pos = 0;
        for(auto num : nums) {
            if(num < 0) {
                neg += 1;
            }
            else if (num > 0)pos++;
        }
        return max(neg,pos);
    }
};