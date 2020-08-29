#include <bits/stdc++.h>
using namespace std;

class Query{
    public:
    int s;
    int e;
    int index;
    int ans;
};

bool comparator(Query q1,Query q2){
    return q1.e < q2.e;
}

bool idx_comparator(Query q1, Query q2){
    return q1.index < q2.index;
}

void update(int *BIT, int index, int n, int val){
    for(;index<=n;index+= (index & (-index))){
        BIT[index]+=val;
    }
}

int query(int *BIT, int index, int n){
    int sum=0;
    for(;index>0;index-=(index&(-index))){
        sum+=BIT[index];
    }
    return sum;
}

vector<int> answers(int *arr, Query *queries, int n,int Q){
    int *BIT=new int[n+1]();
    unordered_map<int,int> umap;
    int q=0;
    for(int i=1;i<=n;i++){
        if(q>=Q){
            break;
        }
        int curr=arr[i];
        update(BIT, i, n, 1);
        if(umap.count(curr) > 0){
            int prev_idx=umap.at(curr);
            update(BIT, prev_idx, n, -1);
            umap.at(curr)=i;
        } else {
            umap[curr]=i;
        }
        int whole=query(BIT, i, n);
        while(q < Q && queries[q].e==i){
            int part=query(BIT, queries[q].s-1, n);
            queries[q].ans=whole - part;
            q++;
        }
        if(q>=Q){
            break;
        }
    }

    vector<int> ans;
    sort(queries, queries+Q, idx_comparator);
    for(int i=0;i<Q;i++){
        ans.push_back(queries[i].ans);
    }
    return ans;
}

int main(){
    int n,q;
    cin>>n;
    int *arr=new int[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cin>>q;
    Query *queries=new Query[q];
    for(int i=0;i<q;i++){
        cin>>queries[i].s>>queries[i].e;
        queries[i].index=i;
    }
    sort(queries, queries+q, comparator);
    vector<int> ans=answers(arr, queries, n, q);
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<endl;
    }
    return 0;
}