#define ll unsigned long long
#define mod 1000000007

void Multiply(ll A[][2], ll M[][2]){
    ll first = ((A[0][0]*M[0][0])%mod + (A[0][1]*M[1][0])%mod) % mod;
    ll second = ((A[0][0]*M[0][1])%mod + (A[0][1]*M[1][1])%mod) % mod;
    ll third = ((A[1][0]*M[0][0])%mod + (A[1][1]*M[1][0])%mod) % mod;
    ll fourth = ((A[1][0]*M[0][1])%mod + (A[1][1]*M[1][1])%mod) % mod;
    A[0][0] = first%mod;
    A[0][1] = second%mod;
    A[1][0] = third%mod;
    A[1][1] = fourth%mod;
}

void fib(ll A[][2], ll n){
    if(n==0 || n==1){
        return;
    }
    fib(A,n/2);
    Multiply(A,A);
    if(n%2!=0){
        ll M[2][2] = {{1,1},{1,0}};
        Multiply(A,M);
    }
}

ll fiboSum(unsigned long long m,unsigned long long n){
    if(m==0 && n==1){
        return 1;
    }
    ll sum_m, sum_n, f_m, f_n;
    ll A1[2][2] = {{1,1},{1,0}};
    ll A2[2][2] = {{1,1},{1,0}};
    if(n==0 || n==1){
        if(n==0){
            f_n = 0;
            sum_n = 0;
        } else if(n==1){
            f_n=1;
            sum_n = 0;
        }
    } else {
        fib(A1,n+1);
        f_n=A1[0][0];
        sum_n = f_n - 1;
    }
    
    if(m==0 || m==1){
        if(m==0){
            f_m=0;
            sum_m = 0;
        } else if(m==1){
            f_m=1;
            sum_m = 0;
        }
    } else {
        fib(A2,m);
        f_m=A2[0][0];
        sum_m = f_m - 1;
    }
    
    // cout<<sum_n%mod<<" "<<sum_m%mod<<endl;
    
    ll ans = (((sum_n)%mod -(sum_m)%mod) + mod)%mod;
    return ans;
}

