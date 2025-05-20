#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs1(int u, const vector<vector<int>>& g, vector<bool>& vis, stack<int>& st) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) dfs1(v, g, vis, st);
    }
    st.push(u);
}

void dfs2(int u, const vector<vector<int>>& gr, vector<int>& comp, int label) {
    comp[u] = label;
    for (int v : gr[u]) {
        if (comp[v] == 0) dfs2(v, gr, comp, label);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1), gr(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a); // grafo transposto
    }

    vector<bool> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs1(i, g, vis, st);
    }

    vector<int> comp(n + 1, 0);
    int label = 0;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (comp[u] == 0) {
            label++;
            dfs2(u, gr, comp, label);
        }
    }

    cout << label << endl;
    for (int i = 1; i <= n; i++) {
        cout << comp[i] << " ";
    }
    cout << endl;
    return 0;
}