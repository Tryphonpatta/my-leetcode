class Solution {
public:
    long long memo[101][15000];
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());

        vector<int> factoryPos;
        for(auto& f : factory){
            for(int i = 0 ; i < f[1] ; i++){
                factoryPos.push_back(f[0]);
            }
        }

        int robotCount = robot.size();
        int factoryCount = factory.size();
        memset(memo,-1,sizeof(memo));
        return rec(0,0,robot,factoryPos);
    }

    long long rec(int robotIdx,int factoryIdx,vector<int> & robot, vector<int> &factoryPos){
        if(robotIdx >= robot.size())return 0;
        if(factoryIdx == factoryPos.size())return 1e12;
        if(memo[robotIdx][factoryIdx] != -1)return memo[robotIdx][factoryIdx];
        long long assign =  abs(robot[robotIdx] - factoryPos[factoryIdx]) +
                           rec(robotIdx + 1, factoryIdx + 1,
                                                robot, factoryPos);
        long long skip = rec(robotIdx, factoryIdx + 1, robot,
                                              factoryPos);
        return memo[robotIdx][factoryIdx] = min(assign,skip);
    }
};