#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    vector<int> bordas;
    int k = pi[n-1];
    while (k > 0) {
        bordas.push_back(k);
        k = pi[k-1];
    }
    if (!bordas.empty()) {
        for (int i = bordas.size()-1; i >= 0; --i) {
            cout << bordas[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}