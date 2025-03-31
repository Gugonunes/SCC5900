#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

void backtrack(int index, const vector<int>& rocks, int lenRocks, vector<int>& currentSubset, vector<vector<int>>& result) {
    if (index == lenRocks) {
        if (!currentSubset.empty()) {
            result.push_back(currentSubset);
        }
        return;
    }

    currentSubset.push_back(rocks[index]);
    backtrack(index + 1, rocks, lenRocks, currentSubset, result);

    currentSubset.pop_back();
    backtrack(index + 1, rocks, lenRocks, currentSubset, result);
}

vector<vector<int>> permutations(const vector<int>& rocks, int lenRocks) {
    vector<vector<int>> result;
    vector<int> currentSubset;
    backtrack(0, rocks, lenRocks, currentSubset, result);
    return result;
}

vector<int> sums(const vector<vector<int>>& subsets) {
    vector<int> result;
    for (const auto& subset : subsets) {
        int sum = 0;
        for (int num : subset) {
            sum += num;
        }
        result.push_back(sum);
    }
    return result;
}

int totalDistinctSums(const vector<int>& possibleSums) {
    set<int> totalSumsSet(possibleSums.begin(), possibleSums.end());
    return totalSumsSet.size();
}

int main() {
    int numOfRobots;
    cin >> numOfRobots;
    vector<int> rocks(numOfRobots);

    for (int i = 0; i < numOfRobots; i++) {
        cin >> rocks[i];
    }

    vector<vector<int>> subsets = permutations(rocks, numOfRobots);
    vector<int> subsetSums = sums(subsets);
    cout << totalDistinctSums(subsetSums);
}