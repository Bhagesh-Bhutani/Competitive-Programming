#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class edge{
    public:
    int v1;
    int v2;
    int cost;
};

class ans{
    public:
    int n_a;
    ll final_cost;
};

bool comparator(edge e1, edge e2){
    return e1.cost<e2.cost;
}

void DFS(vector<int> *edges,int sv,bool *visited){
    visited[sv]=true;
    for(int adj : edges[sv]){
        if(visited[adj]==false){
            DFS(edges,adj,visited);
        }
    }
}

ans* min_cost(vector<edge> *edges, int v,int a){
    ll final_cost=0;
    vector<edge> inc_edges;
    //Union Find Algorithm
    int *parent=new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    for(int i=0;i<edges->size();i++){
        int v1=edges->at(i).v1;
        int v2=edges->at(i).v2;
        int cost=edges->at(i).cost;
        if(cost>=a){
            break;
        }
        int p1=parent[v1];
        int p2=parent[v2];
        while(p1!=v1){
            v1=p1;
            p1=parent[v1];
        }
        while(p2!=v2){
            v2=p2;
            p2=parent[v2];
        }
        if(p1==p2){
            continue;
        } else {
            parent[p2]=p1;
            final_cost+=cost;
            edge e;
            e.v1=v1;
            e.v2=v2;
            e.cost=cost;
            inc_edges.push_back(e);
        }
    }

    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    vector<int> *edges2=new vector<int>[v];
    for(edge e : inc_edges){
        int v1,v2;
        v1=e.v1;
        v2=e.v2;
        edges2[v1].push_back(v2);
        edges2[v2].push_back(v1);
    }
    int c=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFS(edges2,i,visited);
            c++;
        }
    }
    final_cost += c*a;
    ans *myans=new ans();
    myans->n_a=c;
    myans->final_cost=final_cost;
    return myans;
}

int main(){
    int t;
    cin>>t;
    int test_case=1;
    while(t>0){
        int n,m,a;
        cin>>n>>m>>a;
        vector<edge> *edges=new vector<edge>();
        for(int i=0;i<m;i++){
            int x,y,cost;
            cin>>x>>y>>cost;
            edge e;
            e.v1=x-1;
            e.v2=y-1;
            e.cost=cost;
            edges->push_back(e);
        }
        sort(edges->begin(),edges->end(),comparator);
        ans *myans=min_cost(edges,n,a);
        cout<<"Case #"<<test_case<<": "<<myans->final_cost<<" "<<myans->n_a<<endl;
        test_case++;
        t--;
    }
    return 0;
}