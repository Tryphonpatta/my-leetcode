// Last updated: 3/24/2025, 11:06:38 AM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans = 0;
        int end = 0;
        ans += meetings[0][0] - 1;
        for(int i = 0 ; i < meetings.size() - 1; i ++){
            vector<int> meet = meetings[i];
            // cout << meet[0] << " " << meet[1] << endl;
            vector<int> nextMeet = meetings[i + 1];
            end = max(end,meet[1]);
            if(end < nextMeet[0]){
                ans += nextMeet[0] - end - 1;
            }
            else continue;
        }
        end = max(end,meetings.back()[1]);
        ans += days - end;
        return ans;
    }
};