class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int mi = 1, ma = *max_element(nums.begin(), nums.end()),
            totalHouses = nums.size();
        while (mi < ma) {
            int midReward = (mi + ma) / 2;
            int possibleThefts = 0;

            for (int index = 0; index < totalHouses; ++index) {
                if (nums[index] <= midReward) {
                    possibleThefts += 1;
                    index++;  
                }
            }
            if (possibleThefts >= k)
                ma = midReward;
            else
                mi = midReward + 1;
        }

        return mi;
    }
};