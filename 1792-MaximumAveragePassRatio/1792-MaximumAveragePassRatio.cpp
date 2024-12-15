class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue< pair<double,pair<int,int>> > pq;
        for(auto c : classes){
            double pass = c[0],fail = c[1];
            pq.push({(pass + 1)/ (fail + 1) - pass /fail,{pass,fail}});
        }
        while(extraStudents --) {
            double gain = pq.top().first;
            double    pass = pq.top().second.first;
            double    fail = pq.top().second.second;
            pq.pop();
            pq.push({(pass + 2)/(fail + 2) - (pass + 1)/(fail + 1), {pass+1,fail + 1}});
        }
        double ans =0;
        while(!pq.empty()){
            double gain = pq.top().first;
            double    pass = pq.top().second.first;
            double    fail = pq.top().second.second;
            // cout << pass << " "<< fail << endl;
            pq.pop();
            ans += pass / fail;
        }
        return ans / classes.size();
    }
};