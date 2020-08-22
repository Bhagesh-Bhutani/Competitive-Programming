#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

class horse{
    public:
    int vtx=-1;
};

void DFS(horse **board,int sv,int i,int j,int n,int m,bool *visited, unordered_set<int> *s){
    visited[sv]=true;
    s->insert(sv);
    int r1=i-2;
    int c1r=j+1;
    if(r1>=0 && c1r<m && board[r1][c1r].vtx!=-1 && visited[board[r1][c1r].vtx]==false){
        DFS(board,board[r1][c1r].vtx, r1, c1r, n, m ,visited,s);
    }
    int c1l=j-1;
    if(r1>=0 && c1l>=0 && board[r1][c1l].vtx!=-1 && visited[board[r1][c1l].vtx]==false){
        DFS(board,board[r1][c1l].vtx, r1, c1l, n, m ,visited,s);
    }
    
    int r2=i-1;
    int c2r=j+2;
    if(r2>=0 && c2r<m && board[r2][c2r].vtx!=-1 && visited[board[r2][c2r].vtx]==false){
        DFS(board,board[r2][c2r].vtx, r2, c2r, n, m ,visited,s);
    }
    int c2l=j-2;
    if(r2>=0 && c2l>=0 && board[r2][c2l].vtx!=-1 && visited[board[r2][c2l].vtx]==false){
        DFS(board,board[r2][c2l].vtx, r2, c2l, n, m ,visited,s);
    }
    int r3=i+1;
    if(r3<n && c2r<m && board[r3][c2r].vtx!=-1 && visited[board[r3][c2r].vtx]==false){
        DFS(board,board[r3][c2r].vtx,r3,c2r,n,m,visited,s);
    }
    if(r3<n && c2l>=0 && board[r3][c2l].vtx!=-1 && visited[board[r3][c2l].vtx]==false){
        DFS(board,board[r3][c2l].vtx,r3,c2l,n,m,visited,s);
    }
    int r4=i+2;
    if(r4<n && c1r<m && board[r4][c1r].vtx!=-1 && visited[board[r4][c1r].vtx]==false){
        DFS(board, board[r4][c1r].vtx, r4, c1r, n,m,visited,s);
    }
    if(r4<n && c1l>=0 && board[r4][c1l].vtx!=-1 && visited[board[r4][c1l].vtx]==false){
        DFS(board, board[r4][c1l].vtx, r4, c1l, n,m,visited,s);
    }
    
}

int configs(horse **board,int n,int m,int q, unordered_map<int,pair<int,int>> umap,int *fact){
    bool *visited=new bool[q];
    for(int i=0;i<q;i++){
        visited[i]=false;
    }
    int ans=1;
    for(int i=0;i<q;i++){
        if(visited[i]==false){
            unordered_set<int> *s=new unordered_set<int>();
            DFS(board,i,umap.at(i).first,umap.at(i).second,n,m,visited,s);
            int idx=s->size();
            int val=fact[idx];
            ans=(((ll)ans%mod) * val%mod)%mod;
            delete s;
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,m,q;
        cin>>n>>m>>q;
        int *fact=new int[q+1];
        horse **board=new horse*[n];
        for(int i=0;i<n;i++){
            board[i]=new horse[m];
        }
        unordered_map<int,pair<int,int>> umap;
        for(int i=0;i<q;i++){
            int x,y;
            cin>>x>>y;
            board[x-1][y-1].vtx=i;
            pair<int,int> p;
            p.first=x-1;
            p.second=y-1;
            umap[i]=p;
        }
        fact[1]=1;
        for(int i=2;i<=q;i++){
            int val=(((ll)((i))%mod) * fact[i-1]%mod)%mod;
            fact[i]=val;
        }
        int ans=configs(board,n,m,q,umap,fact);
        cout<<ans<<endl;
        for(int i=0;i<n;i++){
            delete[] board[i];
        }
        delete board;
        t--;
    }
    return 0;
}