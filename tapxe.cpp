#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+3;
long long a[N],res=0,n,m,i,j;
int main(){

    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n-1;i++){
        long long res=m-a[i];
        if(res <=0)continue;
        long long s=upper_bound(a+i+1,a+n,res)-a;
        res=res+max((s-i-1),0LL);
    }cout<<res;
    return 0;
}
