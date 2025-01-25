class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> s(nums);
        sort(s.begin(),s.end());
        unordered_map<int,int> numGroup;
        unordered_map<int,list<int>> g;
        int group = 0;
        g[0] = list<int>();
        g[0].push_back(s[0]);
        for(int i = 1; i < nums.size() ;i++){
            if(s[i] - s[i - 1] > limit){
                group ++;
                g[group] = list<int>();
            }
            numGroup[s[i]] = group;
            g[group].push_back(s[i]);
        }
        vector<int> ans;
        for(int i = 0; i < nums.size() ;i++){
            int x = numGroup[nums[i]];
            int y = g[x].front();
            // cout << y << " ";
            if(!g[x].empty())
                g[x].pop_front();
            ans.push_back(y);
        }
        return ans;
    }
};