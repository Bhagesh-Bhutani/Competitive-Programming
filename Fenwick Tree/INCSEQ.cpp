#include<bits/stdc++.h>
#define ll long long int
#define mod 5000000
using namespace std;

void update(int *BIT, int index, int val){
    for(;index<=100000;index+=(index&(-index))){
        BIT[index]=((ll)BIT[index] + val)%mod;
    }
}

int query(int *BIT, int index){
    int sum=0;
    for(;index>0;index-=(index&(-index))){
        sum = ((ll)sum + BIT[index])%mod;
    }
    return sum;
}

int K_length_seq(int *arr, int n, int K){
    int **BIT=new int*[51];
    for(int i=1;i<=50;i++){
        BIT[i]=new int[100001]();
    }
    for(int i=1;i<=n;i++){
        update(BIT[1], arr[i], 1);
        for(int k=2;k<=50;k++){
            int prev=query(BIT[k-1], arr[i]-1);
            update(BIT[k], arr[i], prev);
        }
    }
    return query(BIT[K],100000);
}

int main(){
    int n,K;
    cin>>n>>K;
    int *arr=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=1;
    }
    int ans=K_length_seq(arr,n,K);
    cout<<ans;
    return 0;
}