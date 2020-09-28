#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll fact(ll n, ll m){
    ll ans = 1;
    for(int i=1;i<=n;i++){
        ans = ((ans%m)*(i%m))%m;
    }
    return ans;
}

int main(){
    int N;
    cin>>N;
    while(N>0){
        ll ans;
        ll T,m;
        cin>>T>>m;
        ll cross = T/m;
        if(cross == 0){
            ans = fact(T,m);
        } else if(cross%2==0){
            ans = fact(T%m , m);
        } else if(cross%2!=0){
            ans = (m-1);
            ans = (((ans%m)*(fact(T%m,m)%m))%m * (-1)%m)%m;
            ans = (ans+m)%m;
        }
        cout<<ans<<"\n";
        N--;
    }
    return 0;
}