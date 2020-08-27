#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class trieNode{
    public:
    trieNode *left=NULL;
    trieNode *right=NULL;
    int lC=0;
    int rC=0;
};

void insert(trieNode *head,int n){
    trieNode *curr=head;
    for(int i=31;i>=0;i--){
        int b= (n>>i)&1;
        if(b==0){
            if(curr->left==NULL){
                curr->left=new trieNode();
            }
            curr->lC++;
            curr=curr->left;
        } else {
            if(curr->right==NULL){
                curr->right=new trieNode();
            }
            curr->rC++;
            curr=curr->right;
        }
    }
}

ll query(trieNode *head,int n,int k){
    trieNode *curr=head;
    ll count=0;
    for(int i=31;i>=0;i--){
        int pb= (n>>i)&1;
        int kb= (k>>i)&1;
        if(pb!=0){
            if(kb==0){
                if(curr->right){
                    curr=curr->right;
                } else {
                    break;
                }
            } else {
                if(curr->right){
                    count+=curr->rC;
                }
                if(curr->left){
                    curr=curr->left;
                } else {
                    break;
                }
            }
        } else {
            if(kb==0){
                if(curr->left){
                    curr=curr->left;
                } else {
                    break;
                }
            } else {
                if(curr->left){
                    count+= curr->lC;
                }
                if(curr->right){
                    curr=curr->right;
                } else {
                    break;
                }
            }
        }
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n,k;
        cin>>n>>k;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        trieNode *head=new trieNode();
        insert(head,0);
        int pre_xor=0;
        ll count=0;
        for(int i=0;i<n;i++){
            pre_xor= (pre_xor^arr[i]);
            ll ans=query(head,pre_xor,k);
            count+=ans;
            insert(head,pre_xor);
        }
        cout<<count<<endl;
        t--;
    }
    return 0;
}