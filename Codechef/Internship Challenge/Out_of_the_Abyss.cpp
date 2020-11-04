#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class vertex{
    public:
    ll vtx;
    ll dist;
};

void BFS(vector<ll> *edges ,ll n,ll m, ll k, bool *sn, ll *queries, ll qu){

    // BFS for all nodes except the special nodes

    for(ll i=0;i<qu;i++){
        ll sv = queries[i];
        queue<vertex> q;
        vertex sv_c;
        sv_c.vtx = sv;
        sv_c.dist = 0;
        ll dist = INT_MAX;
        q.push(sv_c);
        while(q.empty()==false){
            vertex curr = q.front();
            q.pop();
            if(sn[curr.vtx]){
                dist = curr.dist;
                break;
            }
            for(ll adj : edges[curr.vtx]){
                vertex adjc;
                adjc.vtx = adj;
                adjc.dist = curr.dist + 1;
                q.push(adjc);
            }
        }

        if(dist == INT_MAX){
            cout<<-1<<"\n";
        } else {
            cout<<dist<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t>0){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<ll> *edges = new vector<ll>[n]();
        for(int i=0;i<m;i++){
            ll v1,v2;
            cin>>v1>>v2;
            edges[v1-1].push_back(v2-1);
            edges[v2-1].push_back(v1-1);
        }

        bool *sn = new bool[n];
        for(ll i=0;i<n;i++){
            sn[i] = false;
        }
        for(int i=0;i<k;i++){
            ll ele;
            cin>>ele;
            sn[ele-1] = true;
        }

        ll q;
        cin>>q;
        ll *queries = new ll[q];
        for(int i=0;i<q;i++){
            ll ele;
            cin>>ele;
            queries[i] = ele-1;
        }
        BFS(edges, n ,m ,k , sn, queries, q);
        delete[] edges;
        t--;
    }
    return 0;
}