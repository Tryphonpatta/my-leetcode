class Solution {
public:
    int fromLeft[1001] = {};
    int fromRight[1001] = {};
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> v1,v2;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(v1.size() == 0 || nums[i] > v1.back()){
                v1.push_back(nums[i]);
            }
            else {
                auto itr = lower_bound(v1.begin(),v1.end(),nums[i]);
                v1[itr - v1.begin()] = nums[i];
            }
            fromLeft[i] = v1.size();
        }
        for(int i = nums.size() - 1; i >= 0 ; i--)
        {
            if(v2.size() == 0 || nums[i] > v2.back()){
                v2.push_back(nums[i]);
            }
            else {
                auto itr = lower_bound(v2.begin(),v2.end(),nums[i]);
                v2[itr - v2.begin()] = nums[i];
            }
            fromRight[i] = v2.size();
        }
        int ans = 0;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     cout << fromLeft[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     cout << fromRight[i] << " ";
        // }
        for(int i = 1 ; i < nums.size() ; i++){
            if(fromLeft[i] >= 2 && fromRight[i] >= 2) 
                ans = max(ans, fromLeft[i] + fromRight[i] - 1);
        }
        return nums.size() - ans;
    }
};