#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class item{
    public:
    int v;
    int w;
    int index;
};

bool wt_comparator(item i1, item i2){
    return i1.v > i2.v;
}

ll BU(item *items, int n, int c, int *primes){
    ll **base=new ll*[n+1];
    ll **curr=new ll*[n+1];
    for(int i=0;i<=n;i++){
        base[i]=new ll[c+1];
        curr[i]=new ll[c+1];
    }
    for(int i=0;i<=n;i++){
        base[i][0]=0;
        curr[i][0]=0;
    }
    for(int i=0;i<=c;i++){
        base[n][i]=0;
        curr[n][i]=0;
    }
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=c;j++){
            ll a1,a2;
            a1=0;
            a2=0;
            if(j-items[i].w>=0){
                a1=(ll)base[i+1][j-items[i].w] + items[i].v;
            }
            a2=(ll)base[i+1][j];
            base[i][j]=max(a1,a2);
        }
    }
    for(int p=9;p>=0;p--){
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=c;j++){
                ll a1,a2,a3;
                a1=0;
                a2=0;
                a3=0;
                if(j-items[i].w >= 0){
                    a1=(ll)items[i].v * primes[p] + (ll)base[i+1][j-items[i].w];
                    a2=(ll)items[i].v + curr[i+1][j-items[i].w];
                }
                
                a3=curr[i+1][j];
                curr[i][j]=max(max(a1,a2),a3);
            }
        }
        if(p==0){
            break;
        }
        for(int k=0;k<=n;k++){
            delete[] base[k];
        }
        base=curr;
        curr=new ll*[n+1];
        for(int i=0;i<=n;i++){
            curr[i]=new ll[c+1];
            for(int j=0;j<=c;j++){
                curr[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++){
            curr[i][0]=0;
        }
        for(int i=0;i<=c;i++){
            curr[n][i]=0;
        }
    }
    return curr[0][c];
}

int main(){
    int *primes=new int[10];
    primes[9]=2;
    primes[8]=3;
    primes[7]=5;
    primes[6]=7;
    primes[5]=11;
    primes[4]=13;
    primes[3]=17;
    primes[2]=19;
    primes[1]=23;
    primes[0]=29;
    int n,weight;
    cin>>n>>weight;
    item *items=new item[n];
    for(int i=0;i<n;i++){
        cin>>items[i].v>>items[i].w;
        items[i].index=i;
    }
    sort(items,items+n,wt_comparator);
    ll ans=BU(items,n,weight,primes);
    cout<<ans;
    return 0;
}