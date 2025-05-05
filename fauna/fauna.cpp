#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int n;
vector<vector<int>> dist;
vector<vector<int>> dp;

int t_soares(int pos, int mask) {
    if (mask == (1 << n) - 1) {
        return 0; // todas as cidades foram visitadas
    }

    if (dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INF;
    for (int next = 0; next < n; next++) {
        if (!(mask & (1 << next)) && dist[pos][next] != INF) {
            int sub = t_soares(next, mask | (1 << next));
            if (sub != INF)
                ans = min(ans, dist[pos][next] + sub);
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    int m;
    cin >> n >> m;

    dist.assign(n, vector<int>(n, INF));
    dp.assign(n, vector<int>(1 << n, -1));

    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        u--; v--;
        dist[u][v] = d;
        dist[v][u] = d;
    }

    int minCost = t_soares(0, 1);

    if (minCost == INF) {
        cout << -1 << endl;
    } else {
        cout << minCost << endl;
    }

    return 0;
}
