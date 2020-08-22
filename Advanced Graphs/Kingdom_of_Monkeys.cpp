#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void DFS(vector<int> *edges,int sv,bool *visited, unordered_set<int> *component){
    visited[sv]=true;
    component->insert(sv);
    for(int adj : edges[sv]){
        if(visited[adj]==false){
            DFS(edges,adj,visited,component);
        }
    }
}

ll bananas(vector<int> *edges,int v,ll *arr){
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    unordered_set<unordered_set<int>*>* s=new unordered_set<unordered_set<int>*>();
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            unordered_set<int> *component=new unordered_set<int>();
            DFS(edges,i,visited,component);
            s->insert(component);
        }
    }
    ll max_ans=INT_MIN;
    for(auto it=s->begin();it!=s->end();it++){
        unordered_set<int> *component=(*it);
        ll ans=0;
        for(auto it2=component->begin();it2!=component->end();it2++){
            int vtx=(*it2);
            ans += arr[vtx];
        }
        if(ans>max_ans){
            max_ans=ans;
        }
    }
    return max_ans;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int v,e;
        cin>>v>>e;
        vector<int> *edges=new vector<int>[v];
        for(int i=0;i<e;i++){
            int v1,v2;
            cin>>v1>>v2;
            edges[v1-1].push_back(v2-1);
            edges[v2-1].push_back(v1-1);
        }
        ll *arr=new ll[v];
        for(int i=0;i<v;i++){
            cin>>arr[i];
        }
        cout<<bananas(edges,v,arr)<<endl;
        t--;
    }
    return 0;
}