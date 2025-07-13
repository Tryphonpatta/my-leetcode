// Last updated: 7/14/2025, 12:33:38 AM
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0;
        int ans = 0;
        for(int i = 0; i < players.size() ;i++){
            while(j < trainers.size() && trainers[j] < players[i]){
                j++;
            }
            if(j < trainers.size() && players[i] <= trainers[j]){
                j++;
                ans ++;
            }
        }
        return ans;
    }
};