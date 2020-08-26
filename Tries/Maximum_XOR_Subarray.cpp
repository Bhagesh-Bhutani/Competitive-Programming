#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode *left=NULL;
    trieNode *right=NULL;
};

void insert(trieNode *head, int n){
    trieNode *curr=head;
    for(int i=31;i>=0;i--){
        int b = (n>>i)&1;
        if(b==0){
            if(curr->left==NULL){
                curr->left = new trieNode();
            }
            curr=curr->left;
        } else {
            if(curr->right==NULL){
                curr->right =new trieNode();
            }
            curr=curr->right;
        }
    }
}

int query(trieNode *head, int n){
    trieNode *curr=head;
    int Xor=0;
    for(int i=31;i>=0;i--){
        int b = (n>>i)&1;
        if(b==0){
            if(curr->right){
                Xor += 1<<i;
                curr=curr->right;
            } else {
                curr=curr->left;
            }
        } else {
            if(curr->left){
                Xor += 1<<i;
                curr=curr->left;
            } else {
                curr=curr->right;
            }
        }
    }
    return Xor;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    trieNode *head=new trieNode();
    insert(head,0);
    int max_xor_subarray=INT_MIN;
    int prefix=0;
    for(int i=0;i<n;i++){
        prefix = prefix^arr[i];
        int ans=query(head,prefix);
        if(ans>max_xor_subarray){
            max_xor_subarray=ans;
        }
        insert(head,prefix);
    }
    cout<<max_xor_subarray;
    return 0;
}