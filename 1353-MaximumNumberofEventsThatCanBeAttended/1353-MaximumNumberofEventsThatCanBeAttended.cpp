// Last updated: 7/7/2025, 1:18:10 PM
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int i = 0;
        priority_queue<int, vector<int> , greater<int>> pq;
        int day = 0;
        int n = events.size();
        int ans =0 ;
        while(!pq.empty() || i < n){
            if(pq.empty()) {
                day = events[i][0];
            }
            while( i < n && events[i][0] <= day) {
                pq.push(events[i][1]);
                i ++;
            }
            pq.pop();
            ans ++;
            day ++;
            while(!pq.empty() && pq.top() < day) {
                pq.pop();
            }
        }
        return ans;
    }
};