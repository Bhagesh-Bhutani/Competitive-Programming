#include<bits/stdc++.h>
using namespace std;

class input{
    public:
    int ele;
    int index;
};

class Query{
    public:
    int s;
    int e;
    int k;
    int index;
    int ans;
};

bool val_comparator(input i1, input i2){
    return i1.ele > i2.ele;
}

bool idx_comparator(Query q1, Query q2){
    return q1.index < q2.index;
}

bool q_comparator(Query q1, Query q2){
    return q1.k > q2.k;
}

void update(int *BIT, int index, int n){
    for(;index<=n;index+=(index&(-index))){
        BIT[index]++;
    }
}

int query(int *BIT, int index){
    int sum=0;
    for(;index>0;index-=(index&(-index))){
        sum+=BIT[index];
    }
    return sum;
}

void answers(input *arr, int n, Query *queries, int Q){
    int *BIT=new int[n+1]();
    sort(arr+1,arr+n+1,val_comparator);
    sort(queries, queries+Q, q_comparator);
    int i=1;
    for(int j=0;j<Q;j++){
        int end_k=queries[j].k;
        while(i<=n && arr[i].ele>end_k){
            update(BIT, arr[i].index, n);
            i++;
        }
        queries[j].ans=query(BIT, queries[j].e) - query(BIT, queries[j].s-1);
    }
    sort(queries, queries+Q, idx_comparator);
    for(i=0;i<Q;i++){
        cout<<queries[i].ans<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    input *arr=new input[n+1];
    for(int i=1;i<=n;i++){
        cin>>arr[i].ele;
        arr[i].index=i;
    }
    int q;
    cin>>q;
    Query *queries=new Query[q];
    for(int i=0;i<q;i++){
        cin>>queries[i].s>>queries[i].e>>queries[i].k;
        queries[i].index=i;
    }
    answers(arr,n,queries,q);
    return 0;
}