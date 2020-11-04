#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class edge{
    public:
    int v1;
    int v2;
    int w;
};

bool comparator(edge e1,edge e2){
    return e1.w < e2.w;
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        ll a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int p=0;
        vector<edge> edges;
        while(p<s.length() && s[p]!='1'){
            p++;
        }
        if(p==s.length()){
            cout<<0<<"\n";
            t--;
            continue;
        }
        int count = 0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0' && s[i-1]=='1'){
                count++;
            }
        }
        count--;
        int c=0;
        int v1=0;
        int v2=1;
        while(c!=count && p<s.length()){
            while(p<s.length() && s[p]!='0'){
                p++;
            }
            if(p==s.length()){
                break;
            }
            int z=0;
            while(p<s.length() && s[p]!='1'){
                p++;
                z++;
            }
            if(p==s.length()){
                break;
            }
            c++;
            edge e;
            e.v1=v1;
            e.v2=v2;
            e.w = z;
            edges.push_back(e);
            v1++;
            v2++;
        }
        int *parent = new int[count+1];
        for(int i=0;i<=count;i++){
            parent[i] = i;
        }
        int idx=0;
        ll cost=0;
        sort(edges.begin(),edges.end(),comparator);
        while(idx<edges.size()){
            edge e = edges[idx];
            ll temp = e.w*b;
            if(temp < a){
                int v1 = e.v1;
                int v2 = e.v2;
                int p1 = parent[v1];
                int p2 = parent[v2];
                while(v1!=p1){
                    v1 = p1;
                    p1=parent[v1];
                }

                while(v2!=p2){
                    v2 = p2;
                    p2=parent[v2];
                }

                parent[p2] = p1;
                cost += temp;
                idx++;
            } else {
                break;
            }
        }

        unordered_set<int> st;
        for(int i=0;i<=count;i++){
            st.insert(parent[i]);
        }
        ll com = st.size();
        cost += (ll)a*com;
        cout<<cost<<"\n";
        delete[] parent;
        t--;
    }
    return 0;
}