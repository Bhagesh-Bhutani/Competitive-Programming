#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int **edges,int v,int e){
    bool *visited=new bool[v];
    int *cost=new int[v];
    cost[0]=0;
    for(int i=0;i<v;i++){
        if(i!=0){
            cost[i]=INT_MAX;
        }
        visited[i]=false;
    }
    int currv=0;
    while(true){
        visited[currv]=true;
        for(int i=0;i<v;i++){
            if(i==currv){
                continue;
            }
            if(edges[currv][i]!=0 && visited[i]==false){
                if(cost[currv] + edges[currv][i] < cost[i]){
                    cost[i] = cost[currv] + edges[currv][i];
                }
            }
        }
        int new_v=-1;
        int new_wt=INT_MAX;
        for(int i=0;i<v;i++){
            if(visited[i]==false){
                if(cost[i]<new_wt){
                    new_v=i;
                    new_wt=cost[i];
                }
            }
        }
        if(new_v==-1){
            break;
        }
        currv=new_v;
    }
    for(int i=0;i<v;i++){
        cout<<i<<" "<<cost[i]<<endl;
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
    Dijkstra(edges,v,e);
    return 0;
}