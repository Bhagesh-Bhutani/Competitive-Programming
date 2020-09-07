#define ll long long int
#define mod 1000000007

int solveM(int x, int y, int z, int ***dp, string a, string b, string c){
    if(z==0){
        return 1;
    }
    if(dp[x][y][z]!=-1){
        return dp[x][y][z];
    }
    int ways=0;
    for(int i=x-1;i>=0;i--){
        if(a[i]==c[z-1]){
            ways = ((ll)ways + solveM(i, y, z-1,dp,a,b,c))%mod;
        }
    }
    for(int i=y-1;i>=0;i--){
        if(b[i]==c[z-1]){
        	ways = ((ll)ways + solveM(x,i,z-1,dp,a,b,c))%mod;
        }
    }
    dp[x][y][z]=ways;
    return ways;
}

int solve(string a,string b,string c){
    int x=a.length();
    int y=b.length();
    int z=c.length();
    int ***dp=new int**[x+1];
    for(int i=0;i<=x;i++){
        dp[i]=new int*[y+1];
        for(int j=0;j<=y;j++){
            dp[i][j]=new int[z+1];
            for(int k=0;k<=z;k++){
                dp[i][j][k]=-1;
            }
        }
    }
    return solveM(x,y,z,dp,a,b,c);
}