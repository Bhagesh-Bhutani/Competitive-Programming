#include<bits/stdc++.h>
using namespace std;

void update(int *BIT, int index,int n){
    for(;index<=n;index+=((index)&(-index))){
        BIT[index]++;
    }
}

int query(int *BIT, int index){
    int sum=0;
    for(;index>0;index-=(index&(-index))){
        sum+=BIT[index];
    }
    return sum;
}

int main(){
    
    int n=1000000;
    bool *sieve=new bool[n+1];
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i<=n;i++){
        sieve[i]=true;
    }
    int *primes=new int[n+1]();
    primes[0]=0;
    primes[1]=0;
    for(int i=2;i<=sqrt(n);i++){
        if(sieve[i]){
            int j=i;
            while(i*j<=n){
                sieve[i*j]=false;
                j++;
            }
        }
    }
    
    for(int i=2;i<=n;i++){
        if(sieve[i]){
            primes[i]++;
            int j=2;
            while(i*j<=n){
                primes[i*j]++;
                j++;
            }
        }
    }
    
    int **BITS=new int*[11];
    for(int i=0;i<=10;i++){
        BITS[i]=new int[n+1]();
    }
    
    for(int i=1;i<=n;i++){
        if(primes[i]>10){
            continue;
        }
        update(BITS[primes[i]],i,n);
    }
    int t;
    cin>>t;
    while(t>0){
        int a,b,n;
        cin>>a>>b>>n;
        cout<<query(BITS[n],b) - query(BITS[n],a-1)<<"\n";
        t--;
    }
    return 0;
}