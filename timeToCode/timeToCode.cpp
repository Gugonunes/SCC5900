#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    vector<string> results;

    for (int i = 0; i<testCases; i++) {
        int numOfSubjects;
        cin >> numOfSubjects;
        unordered_map<string, int> subjects;

        for (int j = 0; j<numOfSubjects; j++) {
            string subject;
            cin >> subject;
            cin >> subjects[subject];
        }
        int days;
        string subjectRequested;

        cin >> days;
        cin >> subjectRequested;

        string result;
        auto it = subjects.find(subjectRequested);

        if (it == subjects.end()) {
            result = "Deu ruim! Va trabalhar";
        } else {
            int requiredDays = it->second;
            if (requiredDays > days + 5) {
                result = "Deu ruim! Va trabalhar";
            } else if (requiredDays > days) {
                result = "Atrasado";
            } else {
                result = "Ufa!";
            }
        }

        results.push_back("Case " + to_string(i+1) + ": " + result);
    }
    for (const string &result : results) {
        cout << result << endl;
    }
    return 0;
}