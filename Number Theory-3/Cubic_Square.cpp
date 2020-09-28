#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll a,m;
        string b;
        cin>>a;
        cin>>b;
        cin>>m;
        ll val = a;
        ll ans = 1;
        for(int i=b.length()-1;i>=0;i--){
            string ch(1,b[i]);
            int bit = stoi(ch);
            if(bit == 2){
                ans = ((((ans%m)*(val%m))%m)*(val%m))%m;
            } else if(bit==1){
                ans = ((ans%m)*(val%m))%m;
            }
            val = ((((val%m)*(val%m))%m)*(val%m))%m;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}