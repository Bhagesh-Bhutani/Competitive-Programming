#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t>0){
        ll n,k;
        cin>>n>>k;
        ll *arr=new ll[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll d = INT_MAX;
        ll i = 0;
        ll j = k-1;
        while(j<n){
            ll diff = arr[j] - arr[i];
            if(diff < d){
                d = diff;
            }
            i++;
            j++;
        }
        cout<<d<<"\n";
        t--;
    }
    return 0;
}