#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    int max_w=-1;
    trieNode **children=new trieNode*[26];
    trieNode(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};

void insert(trieNode *node, string s, int w){
    if(s.length()==0){
        return;
    }
    char c=s[0];
    int idx=c - 'a';
    if(node->children[idx]!=NULL){
        if(w > node->children[idx]->max_w){
            node->children[idx]->max_w = w;
        }
        insert(node->children[idx], s.substr(1), w);
    } else {
        node->children[idx] = new trieNode();
        node->children[idx]->max_w = w;
        insert(node->children[idx], s.substr(1), w);
    }
}

int query(trieNode *node, string s){
    if(s.length()==0){
        return node->max_w;
    }
    char c=s[0];
    int idx=c - 'a';
    if(node->children[idx]==NULL){
        return -1;
    }
    return query(node->children[idx],s.substr(1));
}

int main(){
    int n,q;
    cin>>n>>q;
    trieNode *head=new trieNode();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int w;
        cin>>w;
        insert(head,s,w);
    }
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        cout<<query(head,s)<<endl;
    }
    return 0;
}