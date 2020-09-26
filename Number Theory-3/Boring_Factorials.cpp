#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mod_exp(ll x,ll n,ll p){
    if(n==0){
        return 1;
    }
    ll val = mod_exp(x,n/2,p);
    ll ans = ((val%p) * (val%p))%p;
    if(n%2!=0){
        ans = ((ans%p)*(x%p))%p;
    }
    return ans;
}

ll fact(ll n, ll p){
    ll ans = -1;
    for(ll i=n+1;i<p;i++){
        ll temp = mod_exp(i,p-2,p);
        ans = ((ans%p) * (temp%p))%p;
    }
    ans = (ans+p)%p;
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll n,p;
        cin>>n>>p;
        if(n>=p){
            cout<<0<<"\n";
        } else {
            ll ans=fact(n,p);
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}