#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>* sieve(){
    ll MAX = 2147483647;
    ll size=sqrt(MAX);
    bool *arr=new bool[size+1];
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i<=size;i++){
        arr[i]=true;
    }
    for(int i=2;i<=size;i++){
        if(arr[i]){
            int j=i+i;
            while(j<=size){
                arr[j] = false;
                j+=i;
            }
        }
    }
    vector<ll> *vec=new vector<ll>();
    for(int i=2;i<=size;i++){
        if(arr[i]){
            vec->push_back(i);
        }
    }
    cout<<endl;
    return vec;
}

void Segmented_Sieve(vector<ll>* primes, ll l, ll r){
    ll size=r-l+1;
    bool *sieve=new bool[size];
    for(int i=0;i<size;i++){
        sieve[i]=true;
    }
    for(int i=0;primes->at(i)<=sqrt(r);i++){
        ll currprime=primes->at(i);
        ll base;
        if(currprime>=l){
            base=currprime + currprime;
        } else {
            base=(l/currprime)*currprime;
            if(base<l){
                base = base + currprime;
            }
        }
        ll j=base;
        while(j-l<size){
            sieve[j-l]=false;
            j+=currprime;
        }
    }

    for(int i=0;i<size;i++){
        if(sieve[i]){
            cout<<i+l<<"\n";
        }
    }
}

int main(){
    int t;
    cin>>t;
    vector<ll> *primes=sieve();
    cout<<endl;
    while(t>0){
        ll L,U;
        cin>>L>>U;
        Segmented_Sieve(primes,L,U);
        t--;
    }
    return 0;
}