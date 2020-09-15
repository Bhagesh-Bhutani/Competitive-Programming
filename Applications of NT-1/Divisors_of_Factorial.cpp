#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        bool *sieve=new bool[n+1];
        for(int i=2;i<=n;i++){
            sieve[i]=true;
        }
        sieve[0]=false;
        sieve[1]=false;
        for(int i=2;i<=sqrt(n);i++){
            if(sieve[i]){
                int j=i;
                while(i*j<=n){
                    sieve[i*j]=false;
                    j++;
                }
            }
        }

        ll ans=1;
        for(int i=2;i<=n;i++){
            if(sieve[i]){
                ll a=0;
                int j=i;
                while(j<=n){
                    a=(a + (ll)n/(ll)j)%mod;
                    j = j*i;
                }
                a= (a+1)%mod;
                ans = ((ans%mod)*(a%mod))%mod;
            }
        }
        cout<<ans<<endl;
        t--;
    }
    return 0;
}