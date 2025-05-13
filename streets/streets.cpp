#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> components;

    // Identificar componentes conectados
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, graph, visited, component);
            components.push_back(component);
        }
    }

    // Determinar as ruas a serem construídas
    int numNewRoads = components.size() - 1;
    vector<pair<int, int>> newRoads;

    for (size_t i = 1; i < components.size(); i++) {
        int a = *max_element(components[i - 1].begin(), components[i - 1].end());
        int b = *max_element(components[i].begin(), components[i].end());
        newRoads.push_back({a, b});
    }

    // Saída
    cout << numNewRoads << endl;
    for (auto& road : newRoads) {
        cout << road.first << " " << road.second << endl;
    }

    return 0;
}