class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        int inDegree[100001] = {};
        for(auto fav:favorite){
            inDegree[fav] ++;
        }
        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if(!inDegree[i])q.push(i);
        }
        vector<int> depth(n,1);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            int nextNode = favorite[x];
            depth[nextNode] = max(depth[nextNode],depth[x] + 1);
            if(--inDegree[nextNode] == 0){
                q.push(nextNode);
            }
        }
        int longestCycle = 0;
        int twoCycle = 0;
        for(int i = 0 ; i < n ; i++){
            if(inDegree[i] == 0)continue;
            int cycleLength = 0;
            int current = i;
            while(inDegree[current] != 0){
                inDegree[current] = 0;
                cycleLength ++;
                current = favorite[current];
            }
            if(cycleLength == 2){
                twoCycle += depth[i] + depth[favorite[i]];
            } else {
                longestCycle = max(longestCycle,cycleLength);
            }
        }
        return max(twoCycle,longestCycle);
    }
};