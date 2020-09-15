#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};

Triplet MMI(int a,int b){
    if(b==0){
        Triplet t;
        t.x=1;
        t.y=0;
        t.gcd=a;
        return t;
    }
    Triplet next=MMI(b,a%b);
    Triplet curr;
    curr.x = next.y;
    curr.y = next.x - (a/b)*next.y;
    curr.gcd=next.gcd;
    return curr;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int a,b,d;
        cin>>a>>b>>d;
        Triplet T = MMI(b,a);
        if(T.gcd==1){
            int y1 = (d * T.x)%a;
            int n = (((float)(d/(float)b) - y1) / (float)a);
            cout<<n+1;
        } else {
            if(d==0){
                cout<<1;
            } else {
                cout<<0;
            }
        }
        cout<<"\n";
        t--;
    }
    return 0;
}