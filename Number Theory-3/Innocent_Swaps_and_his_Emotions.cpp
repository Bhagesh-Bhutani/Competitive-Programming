#include<bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;

ll mod_exp(ll x, ll n){
    if(n==0){
        return 1;
    }
    ll val = mod_exp(x,n/2);
    ll ans = ((val%m)*(val%m))%m;
    if(n%2!=0){
        ans = ((ans%m)*(x%m))%m;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N = 1000001;
    ll *arr=new ll[N];
    arr[0]=1;
    for(int i=1;i<=N;i++){
        arr[i] = ((arr[i-1]%m)*(i%m))%m;
    }
    int t;
    cin>>t;
    while(t>0){
        int n,k;
        cin>>n>>k;
        ll nf = arr[n];
        ll n_kf = arr[n-k];
        ll kf = arr[k];
        ll n_k_inv = mod_exp(n_kf,m-2);
        ll k_inv = mod_exp(kf,m-2);
        ll two_k = mod_exp(2, k);
        ll ans = ((((nf%m)*(n_k_inv%m))%m * (k_inv%m))%m * (two_k%m))%m;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}