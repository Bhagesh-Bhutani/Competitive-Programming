#include<bits/stdc++.h>
#define ll long long int
#define m 1000000007
using namespace std;

void Multiply(ll A[][2], ll M[][2]){
    ll first = ((A[0][0]*M[0][0])%(m-1) + (A[0][1]*M[1][0])%(m-1)) % (m-1);
    ll second = ((A[0][0]*M[0][1])%(m-1) + (A[0][1]*M[1][1])%(m-1)) % (m-1);
    ll third = ((A[1][0]*M[0][0])%(m-1) + (A[1][1]*M[1][0])%(m-1)) % (m-1);
    ll fourth = ((A[1][0]*M[0][1])%(m-1) + (A[1][1]*M[1][1])%(m-1)) % (m-1);
    A[0][0] = first%(m-1);
    A[0][1] = second%(m-1);
    A[1][0] = third%(m-1);
    A[1][1] = fourth%(m-1);
}

void matrix_exp(ll A[][2], ll n){
    if(n==0 || n==1){
        return;
    }
    matrix_exp(A,n/2);
    Multiply(A,A);
    if(n%2!=0){
        ll M[2][2] = {{1,1},{1,0}};
        Multiply(A,M);
    }
}

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
    int t;
    cin>>t;
    while(t>0){
        ll f0,f1,n;
        cin>>f0>>f1>>n;
        ll a,b;
        a = f0 + 1;
        b = f1 + 1;
        ll A[2][2] = {{1,1},{1,0}};
        ll ans;
        if(n==0){
            ans = a - 1;
        } else if(n==1){
            ans = b - 1;
        } else {
            matrix_exp(A,n-1);
            a = mod_exp(a,A[1][0]);
            b = mod_exp(b,A[0][0]);
            ll Gn = ((a%m)*(b%m))%m;
            ans = Gn - 1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}