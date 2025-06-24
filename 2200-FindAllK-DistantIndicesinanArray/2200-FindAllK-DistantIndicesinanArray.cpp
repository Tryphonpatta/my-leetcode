// Last updated: 6/24/2025, 9:32:33 AM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        bool c[1001] = {};
        vector<int> ans;
        for(int i = 0; i < nums.size() ; i ++){
            if(nums[i] == key){
                for(int j = max(i - k,0) ; j < nums.size() && j <= i + k; j++){
                    if(c[j])continue;
                    ans.push_back(j);
                    c[j] = 1;
                }
            }
        }
        return ans;
    }
};