#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> *edges,int sv, bool *visited,stack<int> *s){
    visited[sv]=true;
    for(int i=0;i<edges[sv].size();i++){
        int adj=edges[sv][i];
        if(visited[adj]==false){
            DFS(edges,adj,visited,s);
        }
    }
    s->push(sv);
}

void DFS2(vector<int> *edges,int sv,bool *visited){
    visited[sv]=true;
    for(int i=0;i<edges[sv].size();i++){
        int adj=edges[sv][i];
        if(visited[adj]==false){
            DFS2(edges,adj,visited);
        }
    }
}

int min_dominos(vector<int> *edges,int v){
    stack<int> *s=new stack<int>();
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            DFS(edges,i,visited,s);
        }
    }
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    int count=0;
    while(!s->empty()){
        int ele=s->top();
        s->pop();
        if(visited[ele]==false){
            DFS2(edges,ele,visited);
            count++;
        }
    }
    return count;
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
        }
        cout<<min_dominos(edges,v)<<endl;
        t--;
    }
    return 0;
}