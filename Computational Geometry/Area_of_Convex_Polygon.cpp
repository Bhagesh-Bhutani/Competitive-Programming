#include<bits/stdc++.h>
#define ld long double
#define ll long long int
using namespace std;

ll area(ll *X, ll*Y, int n){
    ld myarea = 0;
    for(int i=1;i<=n-2;i++){
        ld x1 = X[i] - X[0];
        ld y1 = Y[i] - Y[0];
        ld x2 = X[i+1] - X[0];
        ld y2 = Y[i+1] - Y[0];
        myarea += x1*y2 - y1*x2;
    }
    myarea = abs(myarea);
    myarea = myarea/2;
    return (ll)myarea;
}

int main(){
    int n;
    cin>>n;
    ll *X = new ll[n];
    ll *Y = new ll[n];
    for(int i=0;i<n;i++){
        cin>>X[i];
    }
    for(int i=0;i<n;i++){
        cin>>Y[i];
    }
    cout<<area(X,Y,n);
    return 0;
}