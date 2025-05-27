#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long mod_pow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> results;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        results.push_back(mod_pow(a, b, MOD));
    }
    for (long long res : results) {
        cout << res << endl;
    }
    return 0;
}