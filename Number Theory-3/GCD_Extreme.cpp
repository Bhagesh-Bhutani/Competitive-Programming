#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void update(ll *BIT,int N,int index,ll val){
    for(;index<=N;index+=((index)&(-index))){
        BIT[index]+=val;
    }
}

ll query(ll *BIT,int index){
    ll sum=0;
    for(;index>0;index-=((index)&(-index))){
        sum += BIT[index];
    }
    return sum;
}

int main(){
    int N = 1000001;
    ll *phi = new ll[N+1];
    for(int i=0;i<=N;i++){
        phi[i] = i;
    }
    for(int i=2;i<=N;i++){
        if(phi[i] == i){
            ll j=2;
            while(i*j<=N){
                phi[i*j] = (phi[i*j]*(i-1))/i;
                j++;
            }
            phi[i] = i - 1;
        }
    }
    ll *sieve = new ll[N+1];
    for(int i=0;i<=N;i++){
        sieve[i] = 0;
    }
    for(int d=1;d<=N;d++){
        int m=2;
        while(d*m<=N){
            sieve[d*m] += phi[m] * d;
            m++;
        }
    }
    ll *BIT=new ll[N+1]();
    for(int i=2;i<=N;i++){
        update(BIT,N,i,sieve[i]);
    }
    while(true){
        int n;
        cin>>n;
        if(n==0){
            return 0;
        }
        cout<<query(BIT,n)<<"\n";
    }
    return 0;
}