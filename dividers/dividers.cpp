#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count_divisors(int x) {
    int cnt = 0;
    int sq = sqrt(x);
    for (int i = 1; i <= sq; i++) {
        if (x % i == 0) {
            cnt += 2; // i e x/i
            if (i * i == x) cnt--; // se for quadrado perfeito, não conta duas vezes
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    vector<int> results;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        results.push_back(count_divisors(x));
    }
    for (int res : results) {
        cout << res << endl;
    }
    return 0;
}