#include<bits/stdc++.h>
using namespace std;

void DFS(vector<int> *edges, int sv, unordered_set<int> *visited, stack<int> *s){
    visited->insert(sv);
    for(int i=0;i<edges[sv].size();i++){
        if(visited->count(edges[sv][i])==0){
            DFS(edges,edges[sv][i],visited,s);
        }
    }
    s->push(sv);
}

void DFS2(vector<int> *edges, int sv,  unordered_set<int> *visited, unordered_set<int> *component){
    component->insert(sv);
    visited->insert(sv);
    for(int i=0;i<edges[sv].size();i++){
        if(visited->count(edges[sv][i]) == 0){
            DFS2(edges, edges[sv][i], visited, component);
        }
    }
}

vector<int>* Bottom(vector<int> *edges, vector<int> *edgesT,int v){
    stack<int> *s=new stack<int>();
    unordered_set<int> *visited=new unordered_set<int>();
    for(int i=0;i<v;i++){
        if(visited->count(i) > 0){
            continue;
        }
        DFS(edges,i,visited,s);
    }
    visited->clear();
    unordered_set<unordered_set<int>*> *output= new unordered_set<unordered_set<int>*>();
    while(!s->empty()){
        int ele=s->top();
        s->pop();
        if(visited->count(ele) > 0){
            continue;
        }
        unordered_set<int> *component=new unordered_set<int>();
        DFS2(edgesT, ele, visited, component);
        output->insert(component);
    }
    cout<<"Size: "<<output->size()<<endl;
    vector<int> *ans=new vector<int>();
    for(auto it=output->begin();it!=output->end();it++){
        unordered_set<int> *component= (*it);
        bool flag=true;
        for(auto it2=component->begin();it2!=component->end();it2++){
            int ele= (*it2);
            for(int i=0;i<edges[ele].size();i++){
                if(component->count(edges[ele][i]) == 0){
                    flag=false;
                    break;
                }
            }
            if(flag==false){
                break;
            }
        }
        if(flag==true){
            for(auto it2=component->begin();it2!=component->end();it2++){
                int vt = (*it2);
                ans->push_back(vt);
            }
        }
    }
    
    sort(ans->begin(),ans->end());
    return ans;
}

int main(){
    while(true){
        int v,e;
        cin>>v;
        if(v==0){
            return 0;
        }
        cin>>e;
        vector<int> *edges=new vector<int>[v];
        vector<int> *edgesT=new vector<int>[v];
        for(int i=0;i<e;i++){
            int v1,v2;
            cin>>v1>>v2;
            edges[v1-1].push_back(v2-1);
            edgesT[v2-1].push_back(v1-1);
        }
        vector<int> *ans=Bottom(edges,edgesT,v);
        for(auto it=ans->begin();it!=ans->end();it++){
            cout<<(*it)+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
