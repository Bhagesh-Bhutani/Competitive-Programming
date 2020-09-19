#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bool *sieve=new bool[k+1];
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i<=k;i++){
        sieve[i]=true;
    }
    for(int i=2;i<=sqrt(k);i++){
        if(sieve[i]){
            int j=i+i;
            while(j<=k){
                sieve[j]=false;
                j+=i;
            }
        }
    }
    vector<int> primes;
    for(int i=2;i<=k;i++){
        if(sieve[i]){
            primes.push_back(i);
        }
    }
    unordered_map<int,int> kp;
    unordered_map<int,int> wp;
    
    int temp=k;
    int idx=0;
    while(temp!=1 && idx<primes.size()){
        if(temp%primes[idx] == 0){
            temp = temp/primes[idx];
            if(kp.count(primes[idx])>0){
                kp.at(primes[idx]) +=1;
            } else {
                kp[primes[idx]] = 1;
            }
        } else {
            idx++;
        }
    }
    for(auto it=kp.begin();it!=kp.end();it++){
        wp[it->first] = 0;
    }

    int i=0;
    int j=0;
    int ways=0;
    bool f=true;
    while(j<n){
        if(f==true){
            int temp=arr[j];
            int idx=0;
            while(temp!=1 && idx<primes.size()){
                if(temp%primes[idx]==0){
                    temp=temp/primes[idx];
                    if(wp.count(primes[idx]) > 0){
                        wp.at(primes[idx]) += 1;
                    }
                } else {
                    idx++;
                }
            }
        }
        bool flag=true;
        for(auto it=kp.begin();it!=kp.end();it++){
            if(wp.at(it->first) < it->second){
                flag=false;
                break;
            }
        }
        if(flag==true){
            ways += n-j;
            int ele=arr[i];
            int idx=0;
            while(ele!=1 && idx<=primes.size()){
                if(ele%primes[idx]==0){
                    ele = ele/primes[idx];
                    if(wp.count(primes[idx])>0){
                        wp.at(primes[idx])-=1;
                    }
                } else {
                    idx++;
                }
            }
            if(i==j){
                i++;
                j++;
                f=true;
            } else {
                i++;
                f=false;
            }
        } else {
            j++;
            f=true;
        }
    }
    cout<<ways;
    return 0;
}