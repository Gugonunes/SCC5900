#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mergeIntervals(vector<pair<int, int>>& intervals, int size) {
    if (intervals.empty()) return 0;

    sort(intervals.begin(), intervals.end());

    int total = 0;
    pair<int, int> current = intervals[0];

    for (int i = 1; i < size; ++i) {
        if (intervals[i].first <= current.second) {
            current.second = max(current.second, intervals[i].second);
        } else {
            total++;
            current = intervals[i];
        }
    }

    total++;

    return total;
}

int main() {
    int numIntervals;
    cin >> numIntervals;

    vector<pair<int, int>> intervals(numIntervals);
    for (int i = 0; i < numIntervals; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    cout << mergeIntervals(intervals, intervals.size()) << endl;

    return 0;
}