// Last updated: 6/30/2025, 9:10:41 AM
class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
        for(auto num : nums) {
            if(m[num] == 0){
                m[num] ++;
                v.push_back(num);
            }
            else m[num] ++;
        }
        int ans = 0;
        for(auto i : v){
            if(m[i - 1]){
                ans = max(ans, m[i] + m[i - 1]);
            }
            if(m[i + 1]){
                ans = max(ans, m[i] + m[i + 1]);
            }
        }
        return ans;
    }
};