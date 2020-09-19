#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool *marked=new bool[n+1];
    for(int i=0;i<=n;i++){
        marked[i]=false;
    }
    int *lpd=new int[n+1];
    for(int i=1;i<=n;i++){
        lpd[i]=i;
    }
    for(int i=2;i<=n;i++){
        if(lpd[i]==i){
            int j=i+i;
            while(j<=n){
                if(lpd[j]==j){
                    lpd[j]=i;
                }
                j+=i;
            }
        }
    }
    for(int i=n;i>=1;i--){
        if(marked[i]==true){
            continue;
        }
        vector<int> m;
        int temp=i;
        while(temp!=1){
            int p=lpd[temp];
            while(temp%p == 0){
                temp = temp/p;
            }
            for(int step=i;step>=1;step-=p){
                if(marked[step]==false){
                    marked[step]=true;
                    m.push_back(step);
                }
            }
        }
        sort(m.begin(),m.end(),greater<int>());
        for(int j=0;j<m.size();j++){
            cout<<m.at(j)<<" ";
        }
    }
    cout<<1;
    return 0;
}