long long solve(int like[][MAXN],int n){
    long long *dp=new long long[1<<n]();
    dp[(1<<n) - 1]=1;
    int s=(1<<n)-2;
    for(int mask=s;mask>=0;mask--){
        long long ways=0;
        int k=0;
        for(int j=0;j<n;j++){
            if((mask&(1<<j))!=0){
                k++;
            }
        }
        for(int j=0;j<n;j++){
            if((mask&(1<<j))==0 && like[k][j]==1){
                ways += dp[mask|(1<<j)];
            }
        }
        dp[mask]=ways;
    }
    return dp[0];
}