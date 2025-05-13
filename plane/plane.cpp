#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge {
    int to, weight;
};

struct State {
    int node, usedDiscount;
    long long cost;

    bool operator>(const State& other) const {
        return cost > other.cost;
    }
};

long long findMinimumCost(int n, vector<vector<Edge>>& graph) {
    vector<vector<long long>> dp(n + 1, vector<long long>(2, LLONG_MAX));
    priority_queue<State, vector<State>, greater<State>> pq;

    // Começa na cidade 1 sem usar o desconto
    dp[1][0] = 0;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        int node = current.node;
        int usedDiscount = current.usedDiscount;
        long long cost = current.cost;

        if (cost > dp[node][usedDiscount]) continue;

        for (const Edge& edge : graph[node]) {
            // Sem usar o desconto
            if (dp[edge.to][usedDiscount] > cost + edge.weight) {
                dp[edge.to][usedDiscount] = cost + edge.weight;
                pq.push({edge.to, usedDiscount, dp[edge.to][usedDiscount]});
            }

            // Usando o desconto
            if (!usedDiscount) {
                long long discountedCost = cost + edge.weight / 2;
                if (dp[edge.to][1] > discountedCost) {
                    dp[edge.to][1] = discountedCost;
                    pq.push({edge.to, 1, dp[edge.to][1]});
                }
            }
        }
    }

    return min(dp[n][0], dp[n][1]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    cout << findMinimumCost(n, graph) << endl;

    return 0;
}