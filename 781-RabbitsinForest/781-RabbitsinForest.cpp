// Last updated: 4/20/2025, 6:44:00 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;
        for (int i = 0 ; i < answers.size() ; i++) mpp[answers[i]] ++;
        int ans = 0;
        for(auto &p : mpp){
            ans += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        }
        return ans;
    }
};