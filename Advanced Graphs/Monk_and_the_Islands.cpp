#include<bits/stdc++.h>
using namespace std;

int min_bridges(vector<int> *edges,int v){
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    unordered_map<int,int> umap;
    queue<int> q;
    q.push(0);
    visited[0]=true;
    if(v-1==0){
        return 0;
    }
    while(!q.empty()){
        int ele=q.front();
        q.pop();
        for(int i=0;i<edges[ele].size();i++){
            int adj=edges[ele][i];
            if(visited[adj]==false){
                q.push(adj);
                umap[adj]=ele;
                visited[adj]=true;
                if(adj==v-1){
                    int dist=0;
                    int vtx=v-1;
                    while(umap.count(vtx) > 0){
                        vtx=umap.at(vtx);
                        dist++;
                    }
                    return dist;
                }
            }
        }
    }
    return -1;
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
        cout<<min_bridges(edges,v)<<endl;
        t--;
    }
    return 0;
}