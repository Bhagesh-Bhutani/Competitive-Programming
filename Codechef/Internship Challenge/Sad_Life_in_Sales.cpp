#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class vtx_wt{
    public:
    ll vtx;
    ll w;
};

class vertex{
    public:
    ll vtx;
    ll dist;
};

void BFS(vector<vtx_wt> *edges, ll n,ll q,ll r, ll v1, ll v2){
    queue<vertex> primary;
    vertex sv;
    sv.vtx = v1;
    sv.dist = 0;
    primary.push(sv);
    ll ans = INT_MAX;
    while(primary.empty()==false){
        vertex curr = primary.front();
        primary.pop();
        if(curr.vtx == v2){
            ans = curr.dist;
            break;
        }
        for(vtx_wt adj : edges[curr.vtx]){
            vertex adjc;
            adjc.vtx = adj.vtx;
            adjc.dist = curr.dist + adj.w;
            primary.push(adjc);
        }
    }
    cout<<ans<<"\n";
}



int main(){
    ll t;
    cin>>t;
    while(t>0){
        ll n,q,r;
        cin>>n>>q>>r;
        vector<vtx_wt> *edges = new vector<vtx_wt>[n]();
        for(ll i=0;i<n-1;i++){
            ll v1,v2,w;
            cin>>v1>>v2>>w;
            vtx_wt vt1,vt2;
            vt1.vtx = v1-1;
            vt1.w = w;
            vt2.vtx = v2 - 1;
            vt2.w = w; 
            edges[v1-1].push_back(vt2);
            edges[v2-1].push_back(vt1);
        }
        for(int i=0;i<q;i++){
            ll v1,v2;
            cin>>v1>>v2;
            BFS(edges, n, q, r, v1 - 1, v2 - 1);
        }
        t--;
    }
    return 0;
}