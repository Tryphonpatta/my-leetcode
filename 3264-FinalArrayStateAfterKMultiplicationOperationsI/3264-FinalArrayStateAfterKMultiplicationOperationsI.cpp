class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size());
        priority_queue< pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > pq;
        for(int i = 0 ; i < nums.size() ; i++){
            pq.push({nums[i],i});
        }
        while(k--){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            pq.push({x * multiplier,y});
        }
        while(!pq.empty()){
            int x = pq.top().first;
            int y = pq.top().second;
            pq.pop();
            ans[y] = x;
        }
        return ans;
    }
};