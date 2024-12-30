long long solve(int len, int low, int high, int zero, int one, vector<long long> &dp){

    if(len > high){
        return 0;
    }

    if(dp[len] != -1){
        return dp[len];
    }

    long long retVal = 0;
    //append zero
    if(len >= low){
        retVal += (1 + solve(len+zero, low, high, zero, one, dp))%mod;
    }else{
        retVal += solve(len+zero, low, high, zero, one, dp)%mod;
    }

    //apend one
    if(len >= low){
        retVal += (1 + solve(len+one, low, high, zero, one, dp))%mod;
    }else{
        retVal += solve(len+one, low, high, zero, one, dp)%mod;
    }

    return dp[len] = retVal;
}