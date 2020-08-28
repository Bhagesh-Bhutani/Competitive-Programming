#include<bits/stdc++.h>
using namespace std;

class coder{
    public:
    int x;
    int y;
    int index;
    int ans;
};

bool x_comparator(coder c1, coder c2){
    if(c1.x==c2.x){
        return c1.y < c2.y;
    }
    return c1.x < c2.x;
}

bool idx_comparator(coder c1, coder c2){
    return c1.index < c2.index;
}

void update(int *BIT, int index){
    for(;index<=100000;index += (index&(-index))){
        BIT[index]++;
    }
}

int query(int *BIT, int index){
    int no=0;
    for(;index>0;index-=(index&(-index))){
        no+=BIT[index];
    }
    return no;
}

int main(){
    int n;
    cin>>n;
    coder *arr=new coder[n+1];
    int *BIT=new int[100001]();
    for(int i=1;i<=n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].index=i;
    }
    sort(arr+1,arr+n+1,x_comparator);

    for(int i=1;i<=n;i++){
        // arr[i].ans=query(BIT, arr[i].y-1);
        // update(BIT, arr[i].y);
        int j=i+1;
        int count=0;
        while(j<=n && arr[j].x == arr[i].x && arr[j].y == arr[i].y){
            count++;
            j++;
        }
        int ans=query(BIT, arr[i].y);
        arr[i].ans=ans;
        for(int k=1;k<=count;k++){
            arr[i+k].ans=ans;
        }
        for(int k=0;k<count+1;k++){
            update(BIT, arr[i].y);
        }
        i=i+count;
    }
    sort(arr+1,arr+n+1,idx_comparator);
    for(int i=1;i<=n;i++){
        cout<<arr[i].ans<<endl;
    }
    return 0;
}