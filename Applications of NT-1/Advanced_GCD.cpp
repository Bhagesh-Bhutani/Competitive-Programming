#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll a;
        string b;
        cin>>a>>b;
        ll mod=0;
        for(int i=0;i<b.length();i++){
            mod=((mod*10)%a + (b[i]-'0')%a)%a;
        }
        cout<<gcd(a,mod)<<endl;
        t--;
    }
    return 0;
}