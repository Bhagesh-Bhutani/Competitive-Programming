#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> *edges,int sv,bool *visited,unordered_set<int> *s){
    visited[sv]=true;
    s->insert(sv);
    for(int i=0;i<edges->at(sv).size();i++){
        if(visited[edges->at(sv).at(i)]==false){
            DFS(edges,edges->at(sv).at(i), visited,s);
        }
    }
}

bool Pswaps(vector<vector<int>> *edges,int n,int *p,int *q){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            unordered_set<int> *s=new unordered_set<int>();
            DFS(edges,i,visited,s);
            unordered_set<int> *p_s=new unordered_set<int>();
            unordered_set<int> *q_s=new unordered_set<int>();
            for(auto it=s->begin();it!=s->end();it++){
                int idx=(*it);
                p_s->insert(p[idx]);
                q_s->insert(q[idx]);
            }
            for(auto it=p_s->begin();it!=p_s->end();it++){
                int ele=(*it);
                if(q_s->count(ele)>0){
                    continue;
                }
                delete s;
            	delete p_s;
            	delete q_s;
                return false;
            }
            delete s;
            delete p_s;
            delete q_s;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        vector<vector<int>> *edges=new vector<vector<int>>();
    	int n,m;
    	cin>>n>>m;
        int *p=new int[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        int *q=new int[n];
        for(int i=0;i<n;i++){
            cin>>q[i];
        }
        for(int i=0;i<n;i++){
            vector<int> vec;
            edges->push_back(vec);
        }
        for(int i=0;i<m;i++){
            int v1,v2;
            cin>>v1>>v2;
            edges->at(v1-1).push_back(v2-1);
            edges->at(v2-1).push_back(v1-1);
        }
        bool ans=Pswaps(edges,n,p,q);
        if(ans){
            cout<<"YES";
        } else {
            cout<<"NO";
        }
        cout<<endl;
        t--;
    }
    
    return 0;
}