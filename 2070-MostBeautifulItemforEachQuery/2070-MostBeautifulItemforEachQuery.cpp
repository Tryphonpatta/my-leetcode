class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans(queries.size(),0);
        sort(items.begin(),items.end());
        vector<pair<int,int>> sortQueries;
        for(int i = 0 ; i < queries.size() ; i++){
            sortQueries.push_back({queries[i],i});
        }
        sort(sortQueries.begin(),sortQueries.end());
        int index = 0;
        int maxBeautiful = 0;
        for(int i = 0 ; i < queries.size() ; i++){
            while(index < items.size() && items[index][0] <= sortQueries[i].first){
                maxBeautiful = max(maxBeautiful,items[index][1]);
                index ++;
            }
            ans[sortQueries[i].second] = maxBeautiful;
        }
        return ans;
    }
};