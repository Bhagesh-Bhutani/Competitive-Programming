#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll min_touches(vector<string> *vec, ll **dp,int mask ,int pos, int L){
    if(mask==0){
        return 0;
    }
    int ones=0;
    for(int i=0;i<vec->size();i++){
        if((mask&(1<<i))!=0){
            ones++;
        }
    }
    if(ones==1){
        return 0;
    }
    if(pos>=L){
        return INT_MAX;
    }
    if(dp[mask][pos]!=INT_MAX){
        return dp[mask][pos];
    }
    int newmask1=0;
    int newmask2=0;
    ll touches=0;
    for(int i=0;i<vec->size();i++){
        if((mask&(1<<i)) != 0){
            touches++;
            if(vec->at(i)[pos]=='0'){
                newmask1 = (newmask1 | (1<<i));
            } else {
                newmask2 = (newmask2 | (1<<i));
            }
        }
    }
    //filter out
    ll t1=min_touches(vec, dp, newmask1, pos+1, L);
    ll t2=min_touches(vec, dp, newmask2, pos+1, L);

    //leave out the current position filtering
    ll t3=min_touches(vec, dp, mask, pos+1, L);
    ll ans=min(t1 + t2 + touches , t3);
    dp[mask][pos]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<string> *vec=new vector<string>();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vec->push_back(s);
    }
    ll **dp=new ll*[1<<n];
    int L=vec->at(0).size();
    for(int i=0;i<(1<<n);i++){
        dp[i]=new ll[L];
        for(int j=0;j<L;j++){
            dp[i][j]=INT_MAX;
        }
    }
    cout<<min_touches(vec, dp, (1<<n)-1,0, L)<<endl;
    return 0;
}