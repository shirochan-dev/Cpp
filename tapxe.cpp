#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
long long a[N],ans=0,n,m,i,j;
int main(){

    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        long long res = m-a[i];
        if(res <=0) continue;
        long long s = upper_bound(a+i+1,a+n,res) - a;
        ans = ans + max((s-i-1),0LL);
    }
    cout<<ans;
    return 0;
}
