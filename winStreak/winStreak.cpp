#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxCrossingSum(const vector<int>& bets, int left, int mid, int right) {
    int leftSum = INT_MIN, rightSum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= left; --i) {
        sum += bets[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= right; ++i) {
        sum += bets[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubarraySum(const vector<int>& bets, int left, int right) {
    if (left == right) {
        return bets[left];
    }

    int mid = left + (right - left) / 2;

    int leftMax = maxSubarraySum(bets, left, mid);
    int rightMax = maxSubarraySum(bets, mid + 1, right);
    int crossMax = maxCrossingSum(bets, left, mid, right);

    return max({leftMax, rightMax, crossMax});
}

int main() {
    int numBets;
    cin >> numBets;

    vector<int> bets(numBets);
    for (int i = 0; i < numBets; ++i) {
        cin >> bets[i];
    }
    cout << maxSubarraySum(bets, 0, numBets - 1) << endl;

    return 0;
}