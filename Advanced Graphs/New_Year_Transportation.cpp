#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int> *edges,int sv, int dest, bool *visited){
    visited[sv]=true;
    if(sv==dest){
        return true;
    }
    for(int i=0;i<edges[sv].size();i++){
        int adj=edges[sv][i];
        if(visited[adj]==false){
            bool bl=DFS(edges,adj,dest,visited);
            if(bl==true){
                return true;
            }
        }
    }
}

int main(){
    int n,t;
    cin>>n>>t;
    vector<int> *edges=new vector<int>[n];
    for(int i=0;i<n-1;i++){
        int dist;
        cin>>dist;
        edges[i].push_back(i+dist);
    }
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    bool ans=DFS(edges,0,t-1,visited);
    if(ans){
        cout<<"YES";
    } else {
        cout<<"NO";
    }
    cout<<endl;
    return 0;
}