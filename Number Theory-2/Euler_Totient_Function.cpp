#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int *sieve=new int[n+1];
    for(int i=0;i<=n;i++){
        sieve[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(sieve[i]==i){
            int j=i+i;
            while(j<=n){
                sieve[j] = (sieve[j]/i)*(i-1);
                j+=i;
            }
            sieve[i] = i-1;
        }
    }
    for(int i=0;i<=n;i++){
        cout<<sieve[i]<<" ";
    }
    return 0;
}