#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node {
    int x,y;

    Node() {
        x = 0;
        y = 0;
    }
};

const int maxN = (int)(1e3);
int n,m;
int dp[maxN+5][maxN+5][2];
Node a[maxN+5],b[maxN+5];
int dist(Node A, Node B) {
    return (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= m; i++)
        cin >> b[i].x >> b[i].y;
    memset(dp,127,sizeof(dp));
    dp[1][0][0] = 0;
    dp[1][1][1] = dist(a[1],b[1]);
    for (int j = 2; j <= m; j++)
        dp[1][j][1] = dp[1][j-1][1] + dist(b[j],b[j-1]);
    for (int i = 2; i <= n; i++)
        dp[i][0][0] = dp[i-1][0][0] + dist(a[i],a[i-1]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j][0] = min({dp[i][j][0],
                               dp[i-1][j][0] + dist(a[i],a[i-1]),
                               dp[i-1][j][1] + dist(a[i],b[j])});
            dp[i][j][1] = min({dp[i][j][1],
                               dp[i][j-1][0] + dist(a[i],b[j]),
                               dp[i][j-1][1] + dist(b[j],b[j-1])});
        }
    }
    cout << dp[n][m][0];
}
