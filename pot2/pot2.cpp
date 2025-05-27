#include <iostream>
#include <vector>
using namespace std;

const long long MOD = 1000000007;

long long mod_pow(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<long long> results;
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        long long exp = mod_pow(b, c, MOD - 1);
        results.push_back(mod_pow(a, exp, MOD));
    }
    for (long long res : results) {
        cout << res << endl;
    }
    return 0;
}