#include <bits/stdc++.h>
using namespace std;
//----------------------------------//
#define endl "\n"
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
// const ll INF = 1000000000000;
const int DIM = 100007;
const int MAXNUMBER = 100003;
#define INF 1000000007;
//----------------------------------//
ll G[DIM], NG[DIM], w[DIM];
vector<int> A[DIM];
void dfs(int v, int parent)
{
    G[v] = w[v];
    NG[v] = 0;
    for (auto x : A[v])
        if (x != parent)
        {
            int to = x;
            dfs(to, v);
            G[v] += NG[to];
            NG[v] += max(G[to], NG[to]);
        }
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll v1, v2;
        cin >> v1 >> v2;
        A[v1].push_back(v2);
        A[v2].push_back(v1);
    }
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    dfs(1, -1);
    cout << max(G[1], NG[1]) << endl;
    // sourse
    return 0;
}