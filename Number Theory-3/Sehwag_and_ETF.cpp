#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define N 1000000
using namespace std;

vector<ll> *primes_vector(){
    bool *primes = new bool[N+1];
    for(int i=0;i<=N;i++){
        primes[i]=true;
    }
    primes[0]=false;
    primes[1]=false;
    for(int i=2;i<=sqrt(N);i++){
        if(primes[i]){
            int j=2;
            while(i*j<=N){
                primes[i*j] = false;
                j++;
            }
        }
    }
    vector<ll> *vec = new vector<ll>();
    for(int i=0;i<=N;i++){
        if(primes[i]){
            vec->push_back(i);
        }
    }
    // delete[] primes;
    return vec;
}

int main(){
    vector<ll> *primes = primes_vector();
    int t;
    cin>>t;
    while(t>0){
        ll L,R,k;
        cin>>L>>R>>k;
        ll size = R-L+1;
        ll *phi = new ll[size];
        ll *product = new ll[size];
        for(ll i=0;i<size;i++){
            phi[i] = i+L;
            product[i] = 1;
        }
        for(int i=0;i<primes->size();i++){
            ll p = primes->at(i);
            ll currprime = primes->at(i);
            if(currprime>=L){
                currprime+=p;
            } else {
                if(L%currprime==0){
                    currprime = currprime * (L/currprime);
                } else {
                    currprime = currprime * (L/currprime);
                    currprime+=p;
                }
            }
            for(;currprime-L<size;currprime+=p){
                phi[currprime-L] = (phi[currprime-L]*(p-1))/p;
                product[currprime-L] *=p;
            }
        }

        ll idx;
        if(L>=N+1){
            idx = 0;
        } else {
            idx = N+1-L;
        }
        for(;idx<size;idx++){
            if(phi[idx] != product[idx]){
                ll p = phi[idx]/product[idx];
                phi[idx] = (phi[idx]*(p-1))/p;
            }
        }
        for(int i=0;i<size;i++){
            if(i==0 && L==1){
                continue;
            }
            if(phi[i]==i+L){
                phi[i] = phi[i] - 1;
            }
        }
        ld num=0;
        for(int i=0;i<size;i++){
            if(phi[i]%k == 0){
                num++;
            }
        }
        ld denom = size;
        ld prob = num/denom;
        cout<<fixed<<setprecision(6)<<prob<<"\n";
        t--;
        delete[] phi;
        delete[] product;
    }
    return 0;
}