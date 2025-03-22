#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> queries;
    std::string ignore;

    for (int i = 0; i<n; i++) {
        int id, tempo;
        cin >> ignore >> id >> tempo;
        queries[id] = tempo;
    }
    int k;
    cin >> k;

    // lógica principal
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila_prioridade;

    for (auto& query : queries) {
        fila_prioridade.push({query.second, query.first});
    }

    for (int i = 0; i < k; i++) {
        auto [time, id] = fila_prioridade.top();
        fila_prioridade.pop();
        
        cout << id << endl;
        fila_prioridade.push({time + queries[id], id});
    }

    return 0;
}