#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int to, rev;
    int cap;
    int orig, dest; // Para guardar a aresta original
};

void add_edge(vector<vector<Edge>>& g, int a, int b) {
    g[a].push_back({b, (int)g[b].size(), 1, min(a, b), max(a, b)});
    g[b].push_back({a, (int)g[a].size() - 1, 1, min(a, b), max(a, b)});
}

int bfs(vector<vector<Edge>>& g, int s, int t, vector<int>& parent, vector<int>& parentEdge) {
    int n = g.size();
    fill(parent.begin(), parent.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            Edge& e = g[u][i];
            if (parent[e.to] == -1 && e.cap > 0) {
                parent[e.to] = u;
                parentEdge[e.to] = i;
                if (e.to == t) return 1;
                q.push(e.to);
            }
        }
    }
    return 0;
}

int edmonds_karp(vector<vector<Edge>>& g, int s, int t) {
    int flow = 0, n = g.size();
    vector<int> parent(n), parentEdge(n);
    while (bfs(g, s, t, parent, parentEdge)) {
        int path_cap = 1e9;
        for (int v = t; v != s; v = parent[v]) {
            path_cap = min(path_cap, g[parent[v]][parentEdge[v]].cap);
        }
        for (int v = t; v != s; v = parent[v]) {
            Edge& e = g[parent[v]][parentEdge[v]];
            e.cap -= path_cap;
            g[v][e.rev].cap += path_cap;
        }
        flow += path_cap;
    }
    return flow;
}

void dfs_cut(int u, vector<vector<Edge>>& g, vector<bool>& vis) {
    vis[u] = true;
    for (auto& e : g[u]) {
        if (e.cap > 0 && !vis[e.to]) {
            dfs_cut(e.to, g, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n + 1);
    vector<pair<int, int>> all_edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(g, a, b);
        all_edges.push_back({min(a, b), max(a, b)});
    }

    int min_cut = edmonds_karp(g, 1, n);

    // Encontrar as arestas do corte mínimo
    vector<bool> vis(n + 1, false);
    dfs_cut(1, g, vis);
    vector<pair<int, int>> cut_edges;
    for (int u = 1; u <= n; u++) {
        if (vis[u]) {
            for (auto& e : g[u]) {
                if (!vis[e.to] && e.orig != 0 && e.dest != 0) {
                    cut_edges.push_back({e.orig, e.dest});
                }
            }
        }
    }

    sort(cut_edges.begin(), cut_edges.end());
    cout << min_cut << endl;
    for (auto& p : cut_edges) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}