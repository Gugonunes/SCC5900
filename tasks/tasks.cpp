#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isValid(const vector<int>& tasks, int k, int maxLoad) {
    int workers = 1;
    int currentLoad = 0;

    for (int task : tasks) {
        if (currentLoad + task > maxLoad) {
            workers++;
            currentLoad = task;

            if (workers > k) {
                return false;
            }
        } else {
            currentLoad += task;
        }
    }

    return true;
}

int minimizeMaxLoad(const vector<int>& tasks, int k) {
    int low = *max_element(tasks.begin(), tasks.end());
    int high = accumulate(tasks.begin(), tasks.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValid(tasks, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int numTasks;
    cin >> numTasks;

    vector<int> tasks(numTasks);
    for (int i = 0; i < numTasks; ++i) {
        cin >> tasks[i];
    }

    int numWorkers;
    cin >> numWorkers;

    cout << minimizeMaxLoad(tasks, numWorkers) << endl;

    return 0;
}