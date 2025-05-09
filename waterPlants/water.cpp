#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int centimeters;
    cin >> centimeters;

    vector<int> growth(12);
    for (int i = 0; i < 12; ++i) {
        cin >> growth[i];
    }

    if (centimeters == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(growth.rbegin(), growth.rend());

    int totalGrowth = 0;
    int months = 0;

    for (int i = 0; i < 12; ++i) {
        totalGrowth += growth[i];
        months++;

        if (totalGrowth >= centimeters) {
            cout << months << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}