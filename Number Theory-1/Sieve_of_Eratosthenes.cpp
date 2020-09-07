#include<bits/stdc++.h>
using namespace std;

int no_of_primes(int n){
    if(n==0 || n==1){
        return 0;
    }
    bool *sieve=new bool[n+1];
    for(int i=0;i<=n;i++){
        sieve[i]=true;
    }
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i<=sqrt(n);i++){
        if(sieve[i]){
            int j=i;
            while(i*j<=n){
                sieve[i*j]=false;
                j++;
            }
        }
    }
    int count=0;
    for(int i=0;i<=n;i++){
        if(sieve[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    cout<<no_of_primes(n);
    return 0;
}