#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode **children=new trieNode*[26];
    bool isTerminal;
    trieNode(){
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
    }
    trieNode(char data){
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isTerminal=false;
        this->data=data;
    }
};

void insert(trieNode *node, string s){
    if(s.length()==0){
        node->isTerminal=true;
        return;
    }
    char c=s[0];
    int idx = c - 'a';
    if(node->children[idx]!=NULL){
        insert(node->children[idx], s.substr(1));
    } else {
        node->children[idx]=new trieNode(s[0]);
        insert(node->children[idx], s.substr(1));
    }
}

void DFS(trieNode *node, string s){
    if(node->isTerminal==true){
        cout<<s<<endl;
    }
    for(int i=0;i<26;i++){
        if(node->children[i]!=NULL){
            string ch(1,node->children[i]->data);
            DFS(node->children[i], s+ch);
        }
    }
}

void query(trieNode *node, string s, string prefix){
    if(s.length()==0){
        DFS(node, prefix);
        return;
    }
    char c=s[0];
    int idx = c - 'a';
    if(node->children[idx]!=NULL){
        query(node->children[idx], s.substr(1), prefix);
    } else {
        cout<<"No suggestions"<<endl;
        insert(node, s);
    }
}

int main(){
    int n,q;
    cin>>n;
    trieNode *node=new trieNode();
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(node,s);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        string s;
        cin>>s;
        query(node,s,s);
    }
    return 0;
}