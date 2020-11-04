#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t>0){
        ll n;
        cin>>n;
        ll *arr=new ll[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll os,es;
        os=0;
        es=0;
        for(int i=0;i<n;i++){
            if((i&1)==0){
                es += arr[i];
            } else {
                os += arr[i];
            }
        }
        ll ans = max(es,os);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}