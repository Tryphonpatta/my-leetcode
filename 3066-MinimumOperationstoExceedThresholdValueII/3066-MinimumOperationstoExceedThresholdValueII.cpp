class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for(int i = 0 ;i < nums.size() ;i++){
            pq.push(nums[i]);
        }
        int ans = 0;
        while(pq.top() < k){
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            pq.push(min(x,y) * 2 + max(x,y));
            ans ++;
        }
        return ans;
    }
};