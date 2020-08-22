#include<bits/stdc++.h>
using namespace std;

void Prims(int **edges,int v,int e){
    bool *visited=new bool[v];
    int *parent=new int[v];
    int *weight=new int[v];
    parent[0]=-1;
    weight[0]=0;
    for(int i=0;i<v;i++){
        if(i!=0){
            weight[i]=INT_MAX;
        }
        visited[i]=false;
    }
    int currv=0;
    while(true){
        visited[currv]=true;
        for(int i=0;i<v;i++){
            if(edges[currv][i]!=0 && visited[i]==false){
                if(edges[currv][i]<weight[i]){
                    weight[i]=edges[currv][i];
                    parent[i]=currv;
                }
            }
        }
        int new_v,new_weight;
        new_v=-1;
        new_weight=INT_MAX;
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                if(weight[i]<new_weight){
                    new_v=i;
                    new_weight=weight[i];
                }
            }
        }
        if(new_v==-1){
            break;
        }
        currv=new_v;
    }
    for(int i=1;i<v;i++){
        int v1=i;
        int v2=parent[i];
        int w=weight[i];
        if(v1<v2){
            cout<<v1<<" "<<v2<<" ";
        } else {
            cout<<v2<<" "<<v1<<" ";
        }
        cout<<w<<endl;
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    int **edges=new int*[v];
    for(int i=0;i<v;i++){
        edges[i]=new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int v1,v2,w;
        cin>>v1>>v2>>w;
        edges[v1][v2]=w;
        edges[v2][v1]=w;
    }
    Prims(edges,v,e);
    return 0;
}