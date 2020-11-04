#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int main(){
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        if(n==1){
            cout<<2<<"\n";
        } else {
            vector<int> vec;
            vec.push_back(2*n);
            int count =0;
            for(int i = 2*n+1;i<=4*n && count<n;i++){
                bool flag = true;
                for(int j=0;j<vec.size();j++){
                    int ans = gcd(vec[j],i);
                    if(ans==1 || ans==vec[j] || ans==i){
                        flag=false;
                        break;
                    }
                    
                }
                if(flag==true){
                        vec.push_back(i);
                        count++;
                    }
            }
            for(int i=0;i<vec.size();i++){
                cout<<vec[i]<<" ";
            }
            cout<<"\n";
        }
        // delete[] sieve;
        t--;
    }
    return 0;
}