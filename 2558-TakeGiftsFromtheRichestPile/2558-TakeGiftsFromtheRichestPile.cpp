class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<long long int> pq;
        long long int ans = 0;
        for(auto gift : gifts) {
            pq.push(gift);
            ans += gift;
        }
        while(k --){
            int x = pq.top();
            pq.pop();
            ans -= x - sqrt(x);
            pq.push(sqrt(x));
        }
        return ans;
    }
};