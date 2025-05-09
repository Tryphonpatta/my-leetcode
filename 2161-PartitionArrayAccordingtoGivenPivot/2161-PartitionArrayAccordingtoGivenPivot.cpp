class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> a, b, c, ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == pivot){
                b.push_back(nums[i]);
            }
            else if (nums[i] < pivot){
                a.push_back(nums[i]);
            }
            else {
                c.push_back(nums[i]);
            }
        }
        for(auto i : a)ans.push_back(i);
        for(auto i : b)ans.push_back(i);
        for(auto i : c)ans.push_back(i);
        return ans;
    }
};