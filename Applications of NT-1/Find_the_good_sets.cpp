#include<bits/stdc++.h>
#define ll long long int
#define MAX_ELE 750001
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int *sieve=new int[MAX_ELE]();
        for(int i=0;i<n;i++){
            sieve[arr[i]]=1;
        }
        
        for(int i=0;i<=MAX_ELE;i++){
            if(sieve[i]>0){
                int j=i+i;
                for(;j<=MAX_ELE;j+=i){
                    if(sieve[j]>0){
                        sieve[j] = ((ll)sieve[j]%mod + sieve[i]%mod)%mod;
                    }
                }
            }
        }
        ll sum =0;
        for(int i=0;i<=MAX_ELE;i++){
            sum = (sum%mod + sieve[i]%mod)%mod;
        }
        cout<<sum<<endl;
        t--;
    }
    return 0;
}