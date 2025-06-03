#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> moves = {2, 3, 5};
    const int MAXN = 1000000;
    vector<bool> win(MAXN + 1, false);

    win[0] = false;

    for (int n = 1; n <= MAXN; n++) {
        for (int m : moves) {
            if (n - m >= 0 && !win[n - m]) {
                win[n] = true;
                break;
            }
        }
    }

    vector<string> resultados;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (win[n])
            resultados.push_back("Tico");
        else
            resultados.push_back("Teco");
    }

    for (const auto& res : resultados) {
        cout << res << endl;
    }
    return 0;
}