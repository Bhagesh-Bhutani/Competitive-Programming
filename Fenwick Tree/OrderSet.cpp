#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class qtype{
    public:
    ll no;
    char ch;
    int rank;
    int index;
};

bool comparator(qtype q1, qtype q2){
    return q1.no < q2.no;
}

bool idx_comparator(qtype q1, qtype q2){
    return q1.index < q2.index;
}

void update(int *BIT, int index, int val, int q){
    for(;index<=q; index += index&(-index)){
        BIT[index] += val;
    }
}

ll query(int *BIT, int index){
    ll sum=0;
    for(;index>0;index -= (index&(-index))){
        sum+=BIT[index];
    }
    return sum;
}

int Ksmaller(int *BIT, int k, int q){
    int lo=1;
    int hi=q;
    int final_ans;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        int ans=query(BIT, mid);
        if(ans > k){
            hi = mid-1;
        } else if(ans < k){
            lo = mid+1;
        } else {
            int front=query(BIT,mid-1);
            if(ans==front){
                hi=mid-1;
            } else{
                final_ans=mid;
                break;
            }
        }
    }
    return final_ans;
}

void insert(int *BIT, int no, int q, unordered_set<ll> &s, int o_no){
    int ans=query(BIT, no);
    int front=query(BIT, no-1);
    if(ans==front){
        s.insert(o_no);
        update(BIT, no, 1, q);
    }
}

void del_query(int *BIT, int no, int q , unordered_set<ll> &s, int o_no){
    int ans=query(BIT, no);
    int front=query(BIT, no-1);
    if(ans!=front){
        s.erase(o_no);
        update(BIT,no, -1, q);
    }
}

void answers(qtype *queries, int q){
    unordered_set<ll> s;
    sort(queries, queries+q, comparator);
    unordered_map<ll,int> umap;
    unordered_map<int,ll> rev;
    int rank=1;
    for(int i=0;i<q;i++){
        if(queries[i].ch=='C' || queries[i].ch=='K'){
            continue;
        }
        if(umap.count(queries[i].no) > 0){
            queries[i].rank=umap.at(queries[i].no);
        } else {
            queries[i].rank=rank;
            umap[queries[i].no]=rank;
            rev[rank]=queries[i].no;
            rank++;
        }
    }
    sort(queries, queries+q, idx_comparator);
    int *BIT=new int[q+1]();
    for(int i=0;i<q;i++){
        char ch=queries[i].ch;
        ll no=queries[i].no;
        // No. of elements smaller than K
        if(ch=='K'){
            int total=query(BIT, q);
            if(no>total){
                cout<<"invalid"<<endl;
            } else {
                int ans=Ksmaller(BIT, no, q);
                ll f_ans=rev.at(ans);
                cout<<f_ans<<endl;
            }
        } else if(ch=='I'){
            insert(BIT, queries[i].rank,q, s, no);
        } else if(ch=='D'){
            del_query(BIT, queries[i].rank, q, s, no);
        } else if(ch=='C'){
            ll eq=INT_MIN;
            int lo=1;
            int hi=rank-1;
            while(lo<=hi){
                int mid=(lo+hi)/2;
                ll ans=rev.at(mid);
                if(ans < no){
                    eq=ans;
                    lo=mid+1;
                } else if(ans > no){
                    hi= mid-1;
                } else {
                    eq=no;
                    break;
                }
            }
            if(eq==INT_MIN){
                cout<<0<<endl;
                continue;
            }
            int r=umap.at(eq);
            if(eq==no){
                cout<<query(BIT,r-1)<<endl;
            } else {
                cout<<query(BIT, r)<<endl;
            }
        }
    }
}

int main(){
    int q;
    cin>>q;
    qtype *queries=new qtype[q];
    for(int i=0;i<q;i++){
        cin>>queries[i].ch>>queries[i].no;
        queries[i].index=i;
    }
    answers(queries, q);
    return 0;
}