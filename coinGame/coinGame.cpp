#include <iostream>
#include <vector>
using namespace std;

const int N = 15;

// Movimentos possíveis
const int dx[] = {-2, -2, +1, -1};
const int dy[] = {+1, -1, -2, -2};

int grundy[N + 1][N + 1];

void precompute() {
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            bool mex[10] = {false};
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
                    int g = grundy[nx][ny];
                    if (g < 10) mex[g] = true;
                }
            }
            int g = 0;
            while (mex[g]) g++;
            grundy[x][y] = g;
        }
    }
}

int main() {
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int nimber = 0;
        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            nimber ^= grundy[x][y];
        }
        if (nimber != 0)
            cout << "Primeiro" << endl;
        else
            cout << "Segundo" << endl;
    }

    return 0;
}
