class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i = 0 ; i< nums.size() -k + 1 ; i++){
            bool c = true;
            for(int j = 1 ; j < k ; j++){
                // cout << nums[j] << " ";
                if(nums[i + j] != nums[i + j - 1] + 1 ){
                    c = false;
                    break;
                }
            }
            // cout << c << endl;
            if(c)ans.push_back(nums[i + k - 1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};