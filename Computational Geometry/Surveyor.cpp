#include<bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

class Point{
    public:
    ll x;
    ll y;
};

ll area(Point *points, int n){
    ld myarea = 0;
    for(int i=1;i<n-1;i++){
        ld x1 = points[i].x - points[0].x;
        ld y1 = points[i].y - points[0].y;
        ld x2 = points[i+1].x - points[0].x;
        ld y2 = points[i+1].y - points[0].y;
        myarea += x1*y2 - y1*x2;
    }
    myarea = abs(myarea);
    myarea = myarea/2;
    return (ll)myarea;
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    ll *dist = new ll[n];
    for(int i=0;i<n;i++){
        cin>>dist[i];
    }
    Point *points = new Point[n];
    points[0].x = 0;
    points[0].y = 0;
    for(int i=0;i<n-1;i++){
        if(s[i]=='N'){
            points[i+1].x = points[i].x;
            points[i+1].y = points[i].y + dist[i];
        } else if(s[i]=='S'){
            points[i+1].x = points[i].x;
            points[i+1].y = points[i].y - dist[i];
        } else if(s[i]=='W'){
            points[i+1].x = points[i].x - dist[i];
            points[i+1].y = points[i].y;
        } else if(s[i]=='E'){
            points[i+1].x = points[i].x + dist[i];
            points[i+1].y = points[i].y;
        }
    }
    cout<<area(points,n);
    return 0;
}