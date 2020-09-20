#define ll long long int

void func(long long n){
    ll *sieve=new ll[n+1];
    for(ll i=0;i<=n;i++){
        sieve[i]=i;
    }
    ll s=0;
    ll sum=0;
    for(ll i=2;i<=n;i++){
        if(sieve[i]==i){
            ll j=i+i;
            while(j<=n){
                sieve[j] = (sieve[j]/i)*(i-1);
                j+=i;
            }
            sieve[i] = i-1;
        }
    }
    for(ll d=2;d<=n;d++){
        if(n%d==0){
            sum += d * sieve[d];
        }
    }
    s=(n*(sum + 2))/2;
    cout<<s;
}
