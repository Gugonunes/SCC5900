#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int N = 7;
const int TOTAL_MOVES = 48;
string path;
bool visited[N + 2][N + 2];

map<char, pair<int, int>> directions = {
    {'D', {0, -1}},
    {'U', {0, 1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}
};

void initialize_visited() {
    for (int i = 0; i < N + 2; ++i) {
        for (int j = 0; j < N + 2; ++j) {
            visited[i][j] = true;
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            visited[i][j] = false;
        }
    }
}

bool validate_borders(int nx, int ny) {
    if (nx < 1 || nx > N || ny < 1 || ny > N) return false;

    if ((visited[nx + 1][ny] && visited[nx - 1][ny] && !visited[nx][ny + 1] && !visited[nx][ny - 1]) ||
        (visited[nx][ny + 1] && visited[nx][ny - 1] && !visited[nx + 1][ny] && !visited[nx - 1][ny])) {
        return false;
    }

    return true;
}

int count_paths(int x, int y, int step) {
    if (x == 1 && y == 1) {
        return step == TOTAL_MOVES ? 1 : 0;
    }
    if (step >= TOTAL_MOVES) return 0;

    visited[x][y] = true;
    int total = 0;

    char expected_move = path[step];

    if (expected_move != '?') {
        auto [dx, dy] = directions[expected_move];
        int nx = x + dx;
        int ny = y + dy;

        if (!visited[nx][ny] && validate_borders(nx, ny)) {
            total += count_paths(nx, ny, step + 1);
        }
    } else {
        for (const auto& [move, dir] : directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (!visited[nx][ny] && validate_borders(nx, ny)) {
                total += count_paths(nx, ny, step + 1);
            }
        }
    }

    visited[x][y] = false;
    return total;
}

int main() {
    cin >> path;

    initialize_visited();
    cout << count_paths(1, N, 0) << endl;
    return 0;
}
